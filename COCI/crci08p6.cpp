// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e5+5;

int N, bit[MM], ansl, ansr, ans[MM];
void update(int pos, int val)
{
    for (int i = pos; i < MM; i += (i&-i)) bit[i]+=val;
}
int query(int pos)
{
    int ret = 0;
    for (int i=pos; i > 0; i -= (i&-i)) ret += bit[i];
    return ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N;
    for (int i = 1, l, r; i <= N; i++) 
    {
        cin >> l >> r;
        ansl = query(l); ansr = query(r);
        cout << ansl + ansr - ans[l] - ans[r] << "\n";
        ans[l] = ansl; ans[r] = ansr;
        update(l+1, 1); update(r, -1);
    }
}