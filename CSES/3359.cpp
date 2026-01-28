#include "iostream"
#include <vector>
#include <utility>
using namespace std;

const int inf = 0x3f3f3f3f;
char A[3003][3003];
bool used[3003][3003];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> A[i][j];
        }
    }
    string ans;
    ans.push_back(A[1][1]);
    vector<pair<int, int>> curr;
    curr.push_back({1, 1});
    while (!curr.empty()) {
        int mn = inf;
        vector<pair<int, int>> tmp;
        for (auto& p : curr) {
            if (p.first + 1 <= N) {
                mn = min(mn, (int) A[p.first + 1][p.second]);
            }
            if (p.second + 1 <= N) {
                mn = min(mn, (int) A[p.first][p.second + 1]);
            }
        }
        for (auto& p : curr) {
            if (p.first + 1 <= N && mn == A[p.first + 1][p.second] && !used[p.first + 1][p.second]) {
                tmp.push_back({p.first + 1, p.second});
                used[p.first + 1][p.second] = true;
            }
            if (p.second + 1 <= N && mn == A[p.first][p.second + 1] && !used[p.first][p.second + 1]) {
                tmp.push_back({p.first, p.second + 1});
                used[p.first][p.second + 1] = true;
            }
        }
        if (mn != inf) {
            ans.push_back(mn);
        }
        swap(tmp, curr);
    }
    cout << ans << "\n";
}
