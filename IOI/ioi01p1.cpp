// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1030;

int bit[MM][MM], S; char op;
void update(int r, int c, int val)
{
    r++;c++;
    for (int i = r; i < MM; i+=i&-i)
    {
        for (int j = c; j < MM; j+=j&-j)
        {
            bit[i][j]+=val;
        }
    }
}
int query(int r, int c)
{
    int ret = 0; r++; c++;
    for (int i = r; i > 0; i-=i&-i)
    {
        for (int j = c; j > 0; j-=j&-j)
        {
            ret += bit[i][j];
        }
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> op >> S;
    while ((cin>>op) && op != '3')
    {
        if (op == '1')
        {
            int x, y, a; cin >> x >> y >> a;
            update(x, y, a);
        }
        else 
        {
            int l, b, r, t;
            cin >> l >> b >> r >> t;
            cout << query(r, t)-query(r, b-1)-query(l-1, t)+query(l-1,b-1) << "\n";
        }
    }
}