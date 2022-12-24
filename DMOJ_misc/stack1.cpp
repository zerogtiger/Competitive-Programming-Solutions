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

int t, m; string a, b; deque<string> dq;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> t >> m;
    for (; t>0; t--)
    {
        cin >> a >> b;
        if (b[0] == 'o') 
        {
            if (m > 0 && dq.front() == a)
            {
                dq.pop_front();
                m--;
            }
            else if (dq.back() == a) 
            {
                dq.pop_back();
            }
        }
        else 
        {
            dq.push_back(a);
        }
    }
    while (!dq.empty())
    {
        cout << dq.front() << endl;
        dq.pop_front();
    }
}