#include "iostream"
#include <map>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    int N, X;
    cin >> N>> X;
    vector<ll> V(N + 1);
    map<ll, int> mp;
    ll ans = 0;
    mp[0] ++;
    for (int i = 1; i <= N; ++i) {
        cin >> V[i];
        V[i] += V[i - 1];
        ans += mp[V[i] - X];
        mp[V[i]]++;
    }
    cout << ans << "\n";
}
