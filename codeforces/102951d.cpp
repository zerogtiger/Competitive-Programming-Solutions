#include "iostream"
#include "map"
#include "vector"
#include <algorithm>
#include <utility>

typedef long long ll;

using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    map<ll, ll> mp;
    for (int i = 0; i < N; ++i) {
        int L, R, D;
        cin >> L >> R >> D;
        mp[L] += D;
        mp[R] -= D;
    }
    vector<pair<ll, ll>> V;
    for (auto& p : mp)
        V.push_back(p);
    V.push_back({-1, 0});
    sort(V.begin(), V.end());
    for (int i = 1; i < V.size(); ++i) {
        V[i].second += V[i - 1].second;
    }
    vector<pair<ll, ll>> psa(V);
    for (int i = 1; i < psa.size(); ++i) {
        psa[i].second += psa[i - 1].second + V[i - 1].second * (V[i].first - V[i - 1].first - 1);
    }
    while (Q--) {
        ll L, R;
        cin >> L >> R;
        size_t LL = upper_bound(psa.begin(), psa.end(), make_pair(L - 1, 0),
                             [](const pair<ll, ll>& x, const pair<ll, ll>& y) {
                                 return x.first < y.first;
                             }) -
                 psa.begin();
        size_t RR = upper_bound(psa.begin(), psa.end(), make_pair(R, 0),
                             [](const pair<ll, ll>& x, const pair<ll, ll>& y) {
                                 return x.first < y.first;
                             }) -
                 psa.begin();
        ll lval = 0;
        ll rval = 0;
        if (LL == psa.size()) {
            lval = 0;
        }
        else {
            lval = psa[LL].second - V[LL].second - V[LL - 1].second * (V[LL].first - L);
        }
        if (RR == psa.size()) {
            rval = psa[psa.size() - 1].second;
        }
        else {
            rval = psa[RR].second - V[RR].second - V[RR - 1].second * (V[RR].first - R);
        }
        cout << rval - lval << "\n";
    }
}
