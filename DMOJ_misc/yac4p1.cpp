// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 2e6+5;

int N, a[MM], ans;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 1; i <= 2*N; i++) 
    {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++) 
    {
        if (a[i] == a[N+i]) ans++;
    }
    cout << ans << endl;
}