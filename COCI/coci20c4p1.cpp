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

int N, M, ans; set<int> s;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) 
    {
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    cin >> M;
    for (int i = 1; i <= M; i++) 
    {
        int k;
        cin >> k;
        bool flag = true;
        for (int j = 1; j <= k; j++) 
        {
            int temp;
            cin >> temp;
            if (s.count(temp) != 0) flag = false;
        }
        ans += flag;
    }
    cout << ans << endl;
}