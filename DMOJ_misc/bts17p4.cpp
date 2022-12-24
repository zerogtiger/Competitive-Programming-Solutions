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

int N, M, J, ans, a[MM];
bool check(int mid)
{
    vector<int> dry;
    dry.push_back(0);
    for (int i = 1; i <= N; i++) 
    {
        if (a[i] <= mid) dry.push_back(i);
    }
    bool flag = true;
    dry.push_back(N+1);
    for (int i = 1; i < dry.size(); i++)
    {
        flag = flag && (dry[i]-dry[i-1] <= J);
    }
    return flag;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> J;
    fill_n(a, MM, 0x3f3f3f3f);
    for (int i = 1; i <= M; i++) 
    {
        int p, t;
        cin >> p >> t;
        a[p] = t;
    }
    int l = 0, r = 1e6+1; 
    ans = 0x3f3f3f3f;
    while (l <= r)
    {
        int mid = (l+r)/2;
        if (check(mid)) 
        {
            ans = mid;
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    cout << (ans == 0x3f3f3f3f? -1: ans) << endl;
}