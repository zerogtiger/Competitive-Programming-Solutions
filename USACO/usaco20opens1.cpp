#include "iostream"
#include "vector"
#include <algorithm>
#include <utility>
using namespace std;

typedef long long ll;

int main()
{
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> P(M);
    for (int i = 0; i < M; ++i) {
        cin >> P[i].first >> P[i].second;
    }
    sort(P.begin(), P.end());
    ll lo = 1, hi = 1e18;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        ll ans = 0;
        ll last = -1e18;
        for (auto &p : P) {
            ll start = max(last + mid, p.first);
            if (start > p.second) {
                continue;
            }
            ans += 1 + (p.second - start)/mid;
            last = start + (p.second - start)/mid * mid;
        }
        if (ans >= N) {
            lo = mid;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << lo << "\n";
}
