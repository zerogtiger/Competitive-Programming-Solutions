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

int N, S, d[MM], Q; set<pi> st[102]; char c;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> S;
    for (int i = 1; i <= N; i++) 
    {
        cin >> d[i];
    }
    for (int i = 1, s, a; i <= S; i++) 
    {
        cin >> s >> a;
        st[a].insert({d[s], s});
    }
    cin >> Q; 
    for (int i = 1, x, k; i <= Q; i++) 
    {
        cin >> c;
        // cout << c << endl;
        if (c == 'A')
        {
            cin >> x >> k;
            st[k].insert({d[x], x});
        }
        else if (c == 'S')
        {
            cin >> x >> k;
            st[k].erase({d[x], x});
        }
        else if (c == 'E')
        {
            cin >> x >> k;
            for (int j = 0; j <= 100; j++) 
            {
                st[j].erase({d[x], x});
            }
            d[x] = k;
        }
        else 
        {
            cin >> k;
            if (st[k].empty()) cout << "-1\n";
            else cout << st[k].begin()->second << "\n";
        }
    }
}