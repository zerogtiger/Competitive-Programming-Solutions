#include "iostream"
#include <queue>
#include <vector>
using namespace std;

bool visited[1008][1008];
int dist[1008][1008];
vector<pair<int, int>> delta = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2},
                                {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
int N;
bool fun(pair<int, int> p) {
    return p.first < 0 || p.first >= N || p.second < 0 || p.second >= N;
}

int main()
{
    cin >> N;
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        for (auto& p : delta) {
            pair<int, int> target = {curr.first + p.first, curr.second + p.second};
            if (fun(target)) {
                continue;
            }
            if (!visited[target.first][target.second]) {
                visited[target.first][target.second] = true;
                dist[target.first][target.second] = dist[curr.first][curr.second] + 1;
                q.push(target);
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << dist[i][j] << (j == N - 1 ? "\n" : " ");
        }
    }
}
