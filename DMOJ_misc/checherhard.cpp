// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 3002;

int M, N; ll bit[MM][MM], a[MM][MM]; char op;
void update(int r, int c, int val)
{
    for (int i = r; i <= M; i+=i&-i)
    {
        for (int j = c; j <= N; j+=j&-j)
        {
            bit[i][j]+=val;
        }
    }
}
ll query(int r, int c)
{
    ll ret = 0;
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

    cin >> M >> N;
    cin >> op;
    while (op != '0')
    {
        if (op=='1')
        {
            int r, c, x; cin >> r >> c >> x;
            if ((r+c)&1==1) x=-x;
            update(r, c, a[r][c]-x);
            a[r][c] = x;
        }
        else 
        {
            int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
            cout << ((r1+c1)&1==1? 1 : -1)*(query(r2, c2)-query(r2, c1-1)-query(r1-1, c2)+query(r1-1, c1-1)) << "\n";
        }
        cin >> op;
    }
}