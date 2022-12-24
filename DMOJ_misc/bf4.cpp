// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e6+5, MOD = 1e9+7;

string S, T; int B = 151; ll pw[MM], hsh[MM];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> S >> T;
    int N = T.length(), M = S.length();
    T = " " + T; S = " " + S;
    ll thsh = 0;
    for (int i = 1; i <= N; i++) 
    {
        thsh = (thsh*B%MOD + T[i])%MOD;
    }
    pw[0] = 1;
    for (int i = 1; i <= M; i++) 
    {
        pw[i] = pw[i-1]*B%MOD;
        hsh[i] = (hsh[i-1]*B%MOD+S[i])%MOD;
        if (i >= N && (hsh[i]-hsh[i-N]*pw[N]%MOD+MOD)%MOD == thsh) 
        {
            cout << i-N << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
}