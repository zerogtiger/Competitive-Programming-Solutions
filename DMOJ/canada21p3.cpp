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

int t, k;
string n;
stack<int> s;
vector<int> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (; t > 0; t--)
    {
        cin >> n >> k;
        s.push(-1);
        int p = 0;

        while (v.size() < k && p < n.length())
        {
            while (s.top() > (n[p] - '0'))
            {
                v.push_back(s.top());
                s.pop();
                if (v.size() >= k)
                    goto outOfLoop;
            }
            s.push(n[p] - '0');
            p++;
        }
    outOfLoop:
        if (n.length() >= k)
        {
            while (v.size() < k && s.top() != -1)
            {
                v.push_back(s.top());
                s.pop();
            }
        }
        sort(v.begin(), v.end());
        stack<int> temp;
        while (s.top()!= -1)
        {
            temp.push(s.top());
            s.pop();
        }
        while (!temp.empty())
        {
            cout << temp.top();
            temp.pop();
        }
        cout << n.substr(p);
        for (auto num : v)
            cout << num;
        cout << endl;
        v.clear();
    }
}
