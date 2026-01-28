// DP + BIT w. coord. comp. for range maximum query
#include "iostream"
#include <map>
#include <vector>
using namespace std;

const int MM = 2e5 + 7;
int bit[MM];
void update(int pos, int val)
{
    for (int i = pos; i < MM; i += (i & -i)) {
        bit[i] = max(bit[i], val);
    }
}

int query(int pos)
{
    int ret = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        ret = max(ret, bit[i]);
    return ret;
}

int main()
{
    int N; cin >> N;
    map<int, int> mp;
    vector<int> V(N);
    for (auto& i : V) {
        cin >> i;
        if (!mp.count(i)) {
            mp[i] = mp.size() + 1;
        }
    }
    int cnt = 1;
    for (auto &p : mp) {
        p.second = cnt++;
    }
    int mx = 0;
    for (auto &ii : V) {
        int i = mp[ii];
        int ret = query(i - 1);
        update(i, ret + 1);
        mx = max(ret + 1, mx);
    }
    cout << mx << "\n";
}
