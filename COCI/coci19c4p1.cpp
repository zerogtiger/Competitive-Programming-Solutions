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

int N; vector<pi> v; ll tot; int cnt;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 1, t, z; i <= N; i++) 
    {
        cin >> t >> z;
        tot += t;
        v.push_back({-z, i});
    }
    sort(v.begin(), v.end());
    vector<pi> out;
    for (auto p: v)
    {
        if (tot >= -p.first) 
        {
            tot += p.first;
            out.push_back({p.second, -p.first});
        }
        else if (tot > 0 && tot < -p.first)
        {
            out.push_back({p.second, tot});
            tot = 0;
        }
        else
        {
            cnt++;
            out.push_back({p.second, 0});
        }
    }
    cout << cnt << endl;
    sort(out.begin(), out.end());
    for (int i = 0; i < out.size(); i++)
    {
        cout << (i == 0? "" : " ") << out[i].second;
    }
    cout << endl;
}