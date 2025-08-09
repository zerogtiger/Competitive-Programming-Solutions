#include "iostream"
#include "vector"
using namespace std;

typedef long long ll;

int main()
{
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int N;
    cin >> N;
    vector<ll> V(N + 2);
    vector<pair<ll, ll>> mod(7, {-1, -1});
    V[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> V[i];
        V[i] += V[i - 1];
        mod[V[i] % 7] = {V[i], i};
    }
    ll ans = 0;
    ll out = 0;
    for (int i = 1; i <= N; ++i) {
        ll val = V[i - 1];
        if (mod[val % 7].first != -1) {
            if (mod[val % 7].first - val > ans && mod[val % 7].second - (i - 1) > out) {
                ans = mod[val % 7].first - val;
                out = mod[val % 7].second - (i - 1);
            }
        }
    }
    cout << out << "\n";
}
