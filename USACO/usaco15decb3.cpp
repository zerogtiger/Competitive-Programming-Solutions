#include "iostream"
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int sick[54];
int main()
{
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    int N, M, D, S;
    cin >> N >> M >> D >> S;
    vector<pair<int, pair<int, int>>> V(D);
    for (auto& p : V) {
        cin >> p.second.first >> p.second.second >> p.first;
    }
    sort(V.begin(), V.end());
    memset(sick, -1, sizeof(sick));
    for (int i = 0; i < S; ++i) {
        int tmp;
        cin >> tmp;
        cin >> sick[tmp];
    }
    int curr[54];
    int ans = 0;
    for (int m = 1; m <= M; ++m) {
        memset(curr, -1, sizeof(curr));
        for (auto& p : V) {
            auto drink = p.second;
            if (drink.second == m && curr[drink.first] < 0) {
                curr[drink.first] = p.first;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= N; ++i) {
            if ((sick[i] > 0 && curr[i] < 0) || (sick[i] > 0 && curr[i] > 0 && sick[i] <= curr[i])) {
                cnt = -1;
                break;
            }
            else if (curr[i] > 0) {
                ++cnt;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}
