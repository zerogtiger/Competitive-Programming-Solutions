// BIT/seg tree + DP
#include "iostream"
#include <map>
#include <vector>
using namespace std;

typedef long long ll;
const int MM = 2e5 + 7, mod = 1e9 + 7;
ll bit[MM];

void update(int pos, int val)
{
    for (int i = pos; i < MM; i += (i & -i))
        bit[i] = (bit[i] + val)%mod;
}

ll query(int pos)
{
    ll ret = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        ret = (ret + bit[i])%mod;
    return ret;
}

int main()
{
    int N;
    cin >> N;
    map<int, int> mp;
    vector<int> V(N + 1);
    for (int i = 1; i <= N; ++i) {
        int x;
        cin >> x;
        V[i] = x;
        mp[x] = 1;
    }
    int cnt = 1;
    for (auto& i : mp) {
        i.second = cnt++;
    }
    for (int k = 1; k <= N; ++k) {
        int i = V[k];
        ll res = query(mp[i] - 1);
        update(mp[i], res + 1);
    }
    cout << query(mp.size()) << "\n";
}
