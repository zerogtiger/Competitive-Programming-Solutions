//Solution by OneZeroGuru on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e5 + 5;

int n, p;
stack<int> s[7];
int cnt = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p;
    for (int i = 1; i <= 6; i++)
    {
        s[i].push(0);
    }
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        while (s[a].top() > b)
        {
            s[a].pop();
            cnt++;
        }
        if (s[a].top() != b)
        {
            s[a].push(b);
            cnt++;
        }
    }
    cout << cnt << endl;
}
