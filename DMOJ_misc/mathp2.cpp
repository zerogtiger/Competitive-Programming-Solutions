// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e5+5, mod = 1e9+7;

int N; ll ans;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) 
    {
        int temp;
        cin >> temp;
        ans = (ans + temp)%mod;
    }
    for (int i = 1; i < N; i++) 
    {
        ans = (2*ans)%mod;
    }
    cout << ans;

}