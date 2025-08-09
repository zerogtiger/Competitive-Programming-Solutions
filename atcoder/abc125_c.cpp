#include "iostream"
#include <numeric>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<ll> V(N + 2);
    for (int i = 1; i <= N; ++i) {
        cin >> V[i];
    }
    vector<ll> pre(N + 2), suf(N + 2);
    pre[0] = 0;
    suf[N + 1] = 0;
    for (int i = 1; i <= N; ++i) {
        pre[i] = gcd(pre[i - 1], V[i]);
        suf[N - i + 1] = gcd(suf[N - i + 2], V[N - i + 1]);
    }
    ll mx = 1;
    for (int i = 1; i <= N; ++i) {
        mx = max(mx, gcd(pre[i - 1], suf[i + 1]));
    }
    // for (auto &i : pre) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    // for (auto &i : suf) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    cout << mx << "\n";
}
