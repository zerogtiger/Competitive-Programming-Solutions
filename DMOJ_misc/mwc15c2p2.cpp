// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e6+5;

int n; stack<pi> s;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    s.push({0x3f3f3f3f, 1});
    for (int i = 1; i <= n; i++) 
    {
        int a; cin >> a;
        while (s.top().first <= a) s.pop();
        cout << (i-s.top().second) << " ";
        s.push({a, i});
    }
    cout << endl;
}
