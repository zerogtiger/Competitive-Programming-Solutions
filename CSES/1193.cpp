#include "iostream"
#include "queue"
#include "vector"
#include <algorithm>
using namespace std;

const int MM = 1003;
vector<string> A;
pair<int, int> par[MM][MM];

int main()
{
    int N, M;
    cin >> N >> M;
    string top(M + 2, '#');
    A.push_back(top);
    for (int i = 1; i <= N; ++i) {
        string tmp(1, '#');
        string t;
        cin >> t;
        t.insert(0, tmp);
        t.push_back('#');
        A.push_back(t);
    }
    A.push_back(top);

    pair<int, int> start, end;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (A[i][j] == 'A') {
                start = {i, j};
            }
        }
    }
    vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;
    A[start.first][start.second] = '#';
    q.push(start);
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        for (auto& d : delta) {
            pair<int, int> nxt = {curr.first + d.first, curr.second + d.second};
            if (A[nxt.first][nxt.second] == 'B') {
                par[nxt.first][nxt.second] = curr;
                end = nxt;
                goto end;
            }
            else if (A[nxt.first][nxt.second] == '.') {
                A[nxt.first][nxt.second] = '#';
                par[nxt.first][nxt.second] = curr;
                q.push(nxt);
            }
        }
    }
    cout << "NO\n";
    return 0;
end:
    auto curr = end;
    string path = "";
    char dir[3][3] = {{' ', 'D', ' '}, {'R', ' ', 'L'}, {' ', 'U', ' '}};
    while (curr != start) {
        auto pre = par[curr.first][curr.second];
        path.push_back(dir[pre.first - curr.first + 1][pre.second - curr.second + 1]);
        curr = pre;
    }
    cout << "YES\n";
    reverse(path.begin(), path.end());
    cout << path.length() << "\n" << path << "\n";
}
