#include "iostream"
#include "vector"
using namespace std;

typedef long long ll;

int N, T;
vector<ll> V;
bool fun(ll t)
{
    ll ans = 0;
    for (auto& i : V) {
        if (ans >= T) {
            return true;
        }
        ans += t/i;
    }
    return ans >= T;
}

int main()
{
    cin >> N >> T;
    V.resize(N);
    ll mn = 0x3f3f3f3f;
    for (auto& i : V) {
        cin >> i;
        mn = min(mn, i);
    }
        
    ll l = 0, r = T*mn;
    while (l < r) {
        ll mid = l + (r - l)/2;
        if (fun(mid)) 
            r = mid;
        else 
            l = mid + 1;
    }
    cout << l << "\n";

}
