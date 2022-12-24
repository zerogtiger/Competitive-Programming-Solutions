// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 3e5+5;

int n, a[MM]; stack<int> s; ll ans;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) 
    {
    while (!s.empty() && a[s.top()] < a[i]) 
        {
            ans += i-s.top()+1;
            s.pop();
        }
        if (!s.empty()) ans += (i-s.top()+1);
        s.push(i);
    }
    cout << ans << endl;
}