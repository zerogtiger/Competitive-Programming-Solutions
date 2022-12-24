// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e6+5, MOD = 1e9+7, base = 131;

string A, B; ll pw[MM], hsha[MM], hshb[MM], ans;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> A >> B;
    int M = A.length(), N = B.length();
    A = " " + A; B = " " + B;
    pw[0] = 1;
    for (int i = 1; i <= M; i++) 
    {
        hsha[i] = (hsha[i-1]*base%MOD+A[i])%MOD;
        pw[i] = pw[i-1]*base%MOD;
    }
    for (int i = 1; i <= N; i++) 
    {
        hshb[i] = (hshb[i-1]*base%MOD+B[i])%MOD;
        pw[i] = pw[i-1]*base%MOD;
    }
    int p = M-min(M, N)+1;
    for (int i = 1; i <= min(M, N); i++) 
    {
        int len = M-p+1;
        if ((hsha[M]-hsha[M-len]*pw[len]%MOD+MOD)%MOD ==
            (hshb[len]-hshb[0]*pw[len]%MOD+MOD)%MOD)
        {
            ans = len;
            break;
        }
        p++;
    }
    cout << A.substr(1) + B.substr(ans+1) << "\n";
}