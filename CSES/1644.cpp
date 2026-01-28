#include "iostream"
#include "vector"
#include "climits"
#include <map>
using namespace std;

typedef long long ll;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    vector<ll> V(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> V[i];
        V[i] += V[i - 1];
    }
    map<ll, int> mp; // value to count

    ll ans = -1e18;

    for (int i = A; i <= N; ++i) {
        mp[V[i - A]]++;
        ans = max(ans, V[i] - mp.begin()->first);
        if (i >= B) {
            if (--mp[V[i - B]] == 0) {
                mp.erase(V[i - B]);
            }
        }
    }
    cout << ans << "\n";
}
