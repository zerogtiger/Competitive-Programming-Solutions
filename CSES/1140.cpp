#include "iostream"
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MM = 4e5 + 7;
ll bit[MM];
void update(int pos, ll val)
{
    for (int i = pos; i < MM; i += (i & -i)) {
        bit[i] = max(bit[i], val);
    }
}

ll query(int pos)
{
    ll ret = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        ret = max(ret, bit[i]);
    return ret;
}

int main()
{
    int N; cin >> N;
    map<int, int> mp;
    vector<tuple<int, int, ll>> V; // ending, starting, payout
    while (N--) {
        int a, b, c;
        cin >> a >> b >> c;
        V.push_back({b, a, c});
        mp[a] = 1;
        mp[b] = 1;
    }
    int cnt = 1;
    for (auto& i : mp) {
        i.second = cnt++;
    }
    ll mx = 0;
    sort(V.begin(), V.end());
    for (auto &t : V) {
        ll val = max(query(mp[get<1>(t)] - 1) + get<2>(t), query(mp[get<0>(t)]));
        mx = max(mx, val);
        update(mp[get<0>(t)], val);
    }
    cout << mx << "\n";

}
