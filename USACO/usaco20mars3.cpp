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

int n, miny[MM], maxy[MM]; vector<pi> v;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    miny[0] = 0x3f3f3f3f;
    maxy[n+1] = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++) 
    {
        miny[i] = min(miny[i-1], v[i-1].second);
        maxy[n-i+1] = max(maxy[n-i+2], v[n-i].second);
    }
    int ans = 1;
    for (int i = 1; i <= n-1; i++) 
    {
        if (miny[i] > maxy[i+1]) ans++;
    }
    cout << ans << endl;
}