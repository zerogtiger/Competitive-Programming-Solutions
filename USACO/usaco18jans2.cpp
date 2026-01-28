#include "iostream"
#include "algorithm"
#include "vector"
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    ll N, M, R;
    cin >> N >> M >> R;
    vector<ll> cows(N);
    for (auto &i : cows)
        cin >> i;
    sort(cows.begin(), cows.end());
    cows.insert(cows.begin(), 0);
    for (ll i =1; i <= N; ++i) {
        cows[i] += cows[i - 1];
    }

    vector<pair<ll, ll>> milk(M);
    for (auto &p : milk)
        cin >> p.second >> p.first;
    sort(milk.rbegin(), milk.rend());
    vector<ll> mpsa;
    vector<ll> profitpsa;
    for (ll i = 0; i < M; ++i) {
        mpsa.push_back(milk[i].second);
        profitpsa.push_back(milk[i].second * milk[i].first);
    }
    mpsa.insert(mpsa.begin(), 0);
    profitpsa.insert(profitpsa.begin(), 0);
    for (ll i = 1; i <= M; ++i) {
        mpsa[i] += mpsa[i - 1];
        profitpsa[i] += profitpsa[i - 1];
    }
    milk.insert(milk.begin(), {0, 0});

    vector<ll> rent(R);
    for (auto &i : rent) 
        cin >> i;
    sort(rent.rbegin(), rent.rend());
    rent.insert(rent.begin(), 0);
    for (ll i = 1; i <= R; ++i)
        rent[i] += rent[i - 1];

    // for (auto &p : milk) {
    //     cout << p.first << " | " << p.second<< ", ";
    // }
    // cout << "\n";
    // for (auto &p : mpsa) {
    //     cout << p << ", ";
    // }
    //
    // cout << "\n";
    // for (auto &p : profitpsa) {
    //     cout << p << ", ";
    // }
    ll ans = 0;
    for (int i = 0; i <= N; ++i) {
        ll curr = rent[i];
        ll milk_left = cows[N]- cows[i];
        ll idx = upper_bound(mpsa.begin(), mpsa.end(), milk_left) - mpsa.begin();
        curr += profitpsa[idx - 1];
        curr += (milk_left - mpsa[idx - 1]) * milk[idx].first;
        ans = max(ans, curr);
    }
    cout << ans << "\n";

}
