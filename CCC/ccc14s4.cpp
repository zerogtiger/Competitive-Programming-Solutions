//Solution by OneZeroGuru on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e3+5;

int n, t, g[2*MM][2*MM];
map<int, int> cx, cy; vector<int> rx, ry;
struct{int l, r, t, b, v;} win[MM];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> t;
    for (int i = 1; i <= n; i++) 
    {
        cin >> win[i].l >> win[i].t >> win[i].r >> win[i].b >> win[i].v;
        cx[win[i].l] = 0; cx[win[i].r] = 0;
        cy[win[i].t] = 0; cy[win[i].b] = 0;
    }
    for (auto &p: cx) 
    {
        p.second = rx.size()+1;
        rx.push_back(p.first);
    } 
    for (auto &p: cy) 
    {
        p.second = ry.size()+1;
        ry.push_back(p.first);
    }
    for (int i = 1; i <= n; i++) 
    {
        int l = win[i].l, r = win[i].r, t = win[i].t, b = win[i].b, v = win[i].v = win[i].v;
        g[cx[l]][cy[t]]+=v; g[cx[r]][cy[t]]-=v;
        g[cx[l]][cy[b]]-=v; g[cx[r]][cy[b]]+=v;
    }
    ll ans = 0;
    for (int i = 1; i <= rx.size(); i++) 
    {
        for (int j = 1; j <= ry.size(); j++) 
        {
            g[i][j] += g[i-1][j] + g[i][j-1] -g[i-1][j-1];
            if (g[i][j] >= t) ans += (ll)(rx[i]-rx[i-1])*(ry[j]-ry[j-1]);
        }
    }
    cout << ans << endl;
}
