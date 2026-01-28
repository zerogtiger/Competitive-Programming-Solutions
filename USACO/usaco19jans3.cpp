#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<ll, ll>> V(N);
    for (auto& p : V) {
        ll a, b;
        cin >> a >> b;
        p.first = a - b;
        p.second = a + b;
    }
    sort(V.begin(), V.end(), [](const pair<ll, ll>& x, const pair<ll, ll>& y) {
        if (x.first == y.first) {
            return x.second > y.second;
        }
        return x.first < y.first;
    });
    ll ans = 0;
    pair<ll, ll> curr = {-3e9, -3e9};
    for (auto &p : V) {
        if (p.second > curr.second) {
            curr = p;
            ans++;
        }
    }
    // for (auto &p : V)
    //     cout << p.first << " | " << p.second << "\n";
    cout << ans << "\n";
}
