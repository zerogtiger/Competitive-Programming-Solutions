#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

int main()
{
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int N, B;
    cin >> N >> B;
    vector<pair<int, int>> X(N);
    vector<pair<int, int>> Y;
    for (auto& p : X) {
        cin >> p.first >> p.second;
        Y.push_back({p.second, p.first});
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    int ans = 0x3f3f3f3f;
    for (auto& xx : X) {
        for (auto& yy : Y) {
            int x = xx.first + 1;
            int y = yy.first + 1;
            int a[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
            for (int i = 0; i < N; ++i) {
                a[(x - X[i].first) / abs(x - X[i].first) + 1]
                 [(y - X[i].second) / abs(y - X[i].second) + 1]++;
            }
            ans = min(ans, max({a[0][0], a[2][2], a[0][2], a[2][0]}));
        }
    }
    cout << ans << "\n";
}
