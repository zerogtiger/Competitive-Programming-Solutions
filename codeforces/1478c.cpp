#include "iostream"
#include "vector"
using namespace std;
typedef long long ll;

int main()
{
    ll T;
    cin >> T;
    while (T--) {
        ll N;
        cin >> N;
        vector<ll> VV(2 * N);
        for (auto& i : VV)
            cin >> i;
        sort(VV.begin(), VV.end());
        vector<ll> V(N);
        ll accum = 0;
        for (ll i = 0; i < N; ++i) {
            if (VV[i * 2] != VV[i * 2 + 1]) {
                cout << "NO\n";
                goto huh;
            }
            else {
                V[i] = VV[i * 2];
            }
        }
        for (int i = 1; i < N; ++i) {
            ll tmp = (V[i] - V[i - 1]) / (2 * i);
            if (V[i] == V[i - 1] || tmp * 2 * i != (V[i] - V[i - 1])) {
                cout << "NO\n";
                goto huh;
            }
            accum += tmp;
        }
        if ((V[N - 1] - 2*N * accum) % (2 * N) != 0 || (V[N - 1] - 2*N * accum) <= 0) {
            cout << "NO\n";
            goto huh;
        }
        cout << "YES\n";
    huh:
        continue;
    }
}
