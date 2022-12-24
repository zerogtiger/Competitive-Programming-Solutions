// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e5 + 5;

stack<int> s;
int n;
ll ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    s.push(-1);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        while (s.top() >= temp)
        {
            ans += (s.top() != temp);
            s.pop();
        }
        if (temp > 0) {
            s.push(temp);
        }
    }
    while (!s.empty())
    {
        s.pop();
        ans++;
    }
    cout << ans - 1 << endl;
}
