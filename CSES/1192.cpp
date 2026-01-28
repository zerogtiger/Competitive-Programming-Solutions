#include "iostream"
#include <queue>
using namespace std;

const int MM = 1003;
char A[MM][MM];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> A[i][j];
        }
    }
    for (int i = 1; i <= N; ++i) {
        A[i][0] = A[i][M + 1] = '#';
    }
    for (int i = 1; i <= M; ++i) {
        A[0][i] = A[N + 1][i] = '#';
    }
    int ans = 0;
    queue<pair<int, int>> q;
    vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (A[i][j] == '.') {
                ans++;
                A[i][j] = '#';
                q.push({i, j});
                while (!q.empty()) {
                    auto p = q.front();
                    q.pop();
                    for (auto &d : delta) {
                        pair<int, int> curr = {p.first + d.first, p.second + d.second};
                        if (A[curr.first][curr.second] == '.') {
                            A[curr.first][curr.second] = '#';
                            q.push(curr);
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}
