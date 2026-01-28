#include "iostream"
#include "map"
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

int main() {
    int N;
    cin >> N;
    map<int, ll> mp;
    while (N--) {
        int i; 
        cin >> i;
        mp[i]++;
    }
    ll ans = 1;
    for (auto &p : mp) {
        ans = ans * (p.second + 1);
        ans = ans % mod;
    }
    cout << ans - 1 << "\n";
}
