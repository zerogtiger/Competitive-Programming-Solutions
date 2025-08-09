#include "iostream"
#include "vector"
#include "map"
using namespace std;

#define x first
#define y second

typedef long long ll;

map<char, pair<ll, ll>> mp = {
    {'L', {-1, 0}},
    {'R', {1, 0}},
    {'U', {0, 1}},
    {'D', {0, -1}},
};

vector<pair<ll, ll>> psa;
bool f(ll mid, vector<pair<ll, ll>>& v, pair<ll, ll> A, pair<ll, ll> B)
{
    ll time_over = mid / (v.size() - 1);
    pair<ll, ll> wind = {A.x + v[v.size() - 1].x * time_over + v[mid % (v.size() - 1)].x,
                         A.y + v[v.size() - 1].y * time_over + v[mid % (v.size() - 1)].y};
    ll dist = abs(B.x - wind.x) + abs(B.y - wind.y);
    return dist <= mid;
}

int main()
{
    pair<ll, ll> A, B;
    cin >> A.x >> A.y >> B.x >> B.y;
    ll N;
    cin >> N;
    string S;
    cin >> S;

    psa.push_back({0, 0});
    for (auto& c : S) {
        psa.push_back({
                psa[psa.size() - 1].x + mp[c].x,
                psa[psa.size() - 1].y + mp[c].y});
    }

    ll lo = 0, hi = 0x3f3f3f3f3f3f3f3f;
    // cout << lo << " | " << hi << "\n";

    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (!f(mid, psa, A, B)) {
            lo = mid;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << (lo == 0x3f3f3f3f3f3f3f3f ? -1 : lo + 1) << "\n";
}
