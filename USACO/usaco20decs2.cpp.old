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

int n, g[2505][2505]; map<int, int> cx, cy; pi in[2505];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> in[i].first >> in[i].second;
        cx[in[i].first] = 0; cy[in[i].second] = 0;
    }
    int cnt = 1;
    for (auto &p: cx) {p.second = cnt++;}
    cnt = 1;
    for (auto &p: cy) {p.second = cnt++;}
    for (int i = 1; i <= n; i++) 
    {
        g[cx[in[i].first]][cy[in[i].second]]++;
    }
    for (int i = 1; i <= cx.size(); i++) 
    {
        for (int j = 1; j <= cy.size(); j++) 
        {
            g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pi &a = in[i];
            pi &b = in[j];
            if (a == b) continue;
            int l = min(cx[a.first], cx[b.first])-1, r = max(cx[a.first], cx[b.first])+1, t = min(cy[a.second], cy[b.second])-1, bot = max(cy[a.second], cy[b.second]);
            int lc = g[l][bot]-g[l][t]+1;
            int rc = g[cx.size()][bot]-g[r-1][bot]-g[cx.size()][t]+g[r-1][t]+1;
            ans += lc*rc;
        }
    }
    cout << (ans)/2+1+n << endl;

}
