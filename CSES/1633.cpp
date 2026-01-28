#include "iostream"
#include <cstring>
#include <map>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
const ll mm = 1e6 + 3;
ll mp[mm];

int fun(int N) {
    if (mp[N] != -1) {
        return mp[N];
    }
    if (N == 0) {
        return mp[N] = 1;
    }
    else {
        ll ret = 0;
        for (int i = 1; i <= min(6, N); ++i) {
            ret = (ret + fun(N - i)) % mod;
        }
        return mp[N] = ret;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(mp, -1, sizeof(mp));
    ll N;
    cin >> N;
    cout << fun(N) << "\n";
}
