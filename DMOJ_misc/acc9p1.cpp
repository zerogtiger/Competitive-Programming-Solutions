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

int t;
set<int> s;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    for (int a[5]; t > 0; t--)
    {
        cin >> a[1] >> a[2] >> a[3] >> a[4];
        for (int i = 2; i <= 4; i++) 
        {
            s.insert(a[1] + a[i]);
        }
        for (int i = 3; i <= 4; i++) 
        {
            s.insert(a[2] + a[i]);
        }
        s.insert(a[3] + a[4]);
        set<int>::iterator it = s.begin();
        cout << s.size() << endl;
        while (it != s.end())
        {
            cout << *it << " " << a[1] + a[2] + a[3] + a[4] - *it << endl;
            it++;
        }
        s.clear();
    }
}