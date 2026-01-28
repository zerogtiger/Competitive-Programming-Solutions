#include "iostream"
#include "vector"
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;
int main() {
    int Q;
    cin >> Q;
    ll accum = 0;
    vector<ll> v;
    for (ll i =0; accum < 1e18; ++i) {
        v.push_back(9 * (ll) pow(10, i) * (i + 1));
        accum += 9 * (ll) pow(10, i) * (i + 1);
        // cout << v[v.size() - 1] << "\n";
    }
    // int j = 1;
    while (Q--) {
        ll K;
        cin >> K;
        ll idx = 0;
        for (; K - v[idx] > 0; ++idx) {
            K -= v[idx];
        }
        // cout << idx << "\n";
        // cout << K << "\n";
        ll num = (K - 1)/(idx + 1) + (ll) pow(10, idx);
        // cout << num << "\n";
        string s = to_string(num);
        ll dig = (K - 1)%(idx + 1);
        cout << s[dig] << "\n";
    }
}
