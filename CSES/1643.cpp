#include "iostream"
#include "vector"
#include <climits>
using namespace std;

typedef long long ll;
int main()
{
    int N;
    cin >> N;
    vector<ll> V(N + 2);
    V[0] = 0;
    ll mn = 0;
    ll ans = LONG_LONG_MIN;
    for (int i = 1; i <= N; ++i) {
        cin >> V[i];
        V[i] += V[i - 1];
        ans = max(ans, V[i] - mn);
        mn = min(mn, V[i]);
    }
    cout << ans << "\n";
}
