#include "iostream"
#include "vector"
#include "algorithm"
#include <climits>
using namespace std;
typedef long long ll;

ll fn(vector<pair<ll, ll>>& V, int N)
{
    sort(V.begin(), V.end());
    vector<ll> mx_rev(N + 1, 0);
    vector<ll> mn_rev(N + 1, 0x3f3f3f3f);
    for (int i = N - 1; i >= 0; --i) {
        mx_rev[i] = max(mx_rev[i + 1], V[i].second);
        mn_rev[i] = min(mn_rev[i + 1], V[i].second);
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    ll mx = 0;
    ll mn = 0x3f3f3f3f;
    for (int i = 0; i < N; ++i) {
        ll curr = 0;
        mx = max(mx, V[i].second);
        mn = min(mn, V[i].second);
        curr += (mx - mn) * (V[i].first - V[0].first);
        if (i != N - 1) {
            curr += (mx_rev[i + 1] - mn_rev[i + 1]) * (V[N - 1].first - V[i + 1].first);
        }
        ans = min(ans, curr);
    }
    return ans;
}

int main()
{
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<ll, ll>> V(N);
    vector<pair<ll, ll>> VV;
    ll minx = 0x3f3f3f3f, maxx = 0, miny = 0x3f3f3f3f, maxy = 0;
    for (auto& p : V) {
        cin >> p.first >> p.second;
        VV.push_back({p.second, p.first});
        minx = min(minx, p.first);
        miny = min(miny, p.second);
        maxx = max(maxx, p.first);
        maxy = max(maxy, p.second);
    }
    ll ans = min(fn(V, N), fn(VV, N));
    cout << (maxx - minx) * (maxy - miny) - ans;
    // cout <<  ans;
}
