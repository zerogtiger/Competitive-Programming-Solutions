#include "iostream"
#include "vector"
using namespace std;

typedef long long ll;

vector<ll> V;

bool f(ll tar, int K)
{
    ll sum = 0;
    int groups = 0;
    for (int i = 0; i < V.size(); ++i) {
        if (V[i] > tar) {
            return true;
        }
        sum += V[i];
        if (sum > tar) {
            sum = V[i];
            groups++;
        }
    }
    // cout << groups << "\n";
    return groups + 1 > K;
}

int main()
{
    int N, K;
    cin >> N >> K;

    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        V.push_back(tmp);
        sum += tmp;
    }
    ll lo = 0, hi = sum;
    // cout << f(8, K);
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (f(mid, K)) {
            lo = mid;
        }
        else {
            hi = mid - 1;
        }
    }
    ll tar = lo + 1;
    sum = 0;
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        sum += V[i];
        if (sum > tar) {
            sum = V[i];
        }
        ans = max(ans, sum);
    }
    cout << ans << "\n";
}
