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

ll bit[2][MM], N, M, a[MM];
void updaten(int idx, int val)
{
    for (int i = idx; i <= N; i += i&-i) bit[0][i]+=val;
}
void updateq(int idx, int val)
{
    for (int i = idx; i < MM; i+=i&-i) bit[1][i]+=val;
}
ll query(int pos, int a)
{
    ll ans = 0;
    for (int i = pos; i > 0; i-=i&-i) ans+=bit[a][i];
    return ans;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1, x; i <= N; i++) 
    {
        cin >> x; a[i] = x; updaten(i, x); updateq(x, 1);
    }
    for (int i = 1, x, k; i <= M; i++) 
    {
        char c; cin >> c;
        if (c == 'C') 
        {
            cin >> x >> k;
            updaten(x, k-a[x]);
            updateq(a[x], -1);
            updateq(k, 1); a[x]=k;
        }
        else if (c == 'S')
        {
            cin >> x >> k;
            cout << query(k, 0)-query(x-1, 0) << "\n";
        }
        else if (c == 'Q')
        {
            cin >> x;
            cout << query(x, 1)<< "\n";
        }
    }
}