#include "iostream"
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int MM = 1005, inf = 0x3f3f3f3f;
int mon[MM][MM];
int a[MM][MM];
pair<int, int> par[MM][MM];
char grid[MM][MM];

inline int clamp(int v, int l, int r) { return min(r, max(v, l)); }

int main()
{
    int N, M;
    cin >> N >> M;
    queue<pair<int, int>> q;
    pair<int, int> start;
    memset(mon, inf, sizeof(mon));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'M') {
                q.push({i, j});
                mon[i][j] = 0;
            }
            else if (grid[i][j] == 'A') {
                start = {i, j};
                grid[i][j] = '.';
            }
        }
    }
    vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        for (auto& d : delta) {
            pair<int, int> nxt = {curr.first + d.first, curr.second + d.second};
            if (clamp(nxt.first, 1, N) != nxt.first || clamp(nxt.second, 1, M) != nxt.second) {
                continue;
            }
            if (mon[nxt.first][nxt.second] == inf && grid[nxt.first][nxt.second] != '#') {
                mon[nxt.first][nxt.second] = mon[curr.first][curr.second] + 1;
                q.push(nxt);
            }
        }
    }
    memset(a, inf, sizeof(a));
    a[start.first][start.second] = 0;
    q.push(start);
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        for (auto& d : delta) {
            pair<int, int> nxt = {curr.first + d.first, curr.second + d.second};
            if (clamp(nxt.first, 1, N) != nxt.first || clamp(nxt.second, 1, M) != nxt.second) {
                continue;
            }
            if (a[nxt.first][nxt.second] == inf && grid[nxt.first][nxt.second] != '#') {
                a[nxt.first][nxt.second] = a[curr.first][curr.second] + 1;
                q.push(nxt);
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (mon[i][j] <= a[i][j]) {
                grid[i][j] = '#';
            }
        }
    }
    q.push(start);
    par[start.first][start.second] = start;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        if ((curr.first == 1 || curr.first == N || curr.second == 1 || curr.second == M)) {
            char dir[3][3] = {{' ', 'D', ' '}, {'R', ' ', 'L'}, {' ', 'U', ' '}};
            string path = "";
            while (curr != start) {
                auto cp = par[curr.first][curr.second];
                path.push_back(dir[cp.first - curr.first + 1][cp.second - curr.second + 1]);
                curr = par[curr.first][curr.second];
            }
            cout << "YES\n" << path.length() << "\n";
            reverse(path.begin(), path.end());
            cout << path;
            return 0;
        }
        for (auto& d : delta) {
            pair<int, int> nxt = {curr.first + d.first, curr.second + d.second};
            if (clamp(nxt.first, 1, N) != nxt.first || clamp(nxt.second, 1, M) != nxt.second) {
                continue;
            }
            if (par[nxt.first][nxt.second] == (pair<int, int>) {0, 0} &&
                grid[nxt.first][nxt.second] != '#') {
                par[nxt.first][nxt.second] = curr;
                q.push(nxt);
            }
        }
    }
    cout << "NO\n";
}
