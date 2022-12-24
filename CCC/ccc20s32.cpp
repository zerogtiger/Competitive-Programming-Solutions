// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 2e5+5, MOD = 1e9+7;

string S, T; int N, H, B1=131, B2=151;
ll hsh1[MM], hsh2[MM], pw1[MM], pw2[MM]; 
set<ll> st;

ll substrHash(int l, int r)
{
    ll v1 = (hsh1[r]-hsh1[l-1]*pw1[r-l+1]%MOD+MOD)%MOD;
    ll v2 = (hsh2[r]-hsh2[l-1]*pw2[r-l+1]%MOD+MOD)%MOD;
    return (v1<<32|v2);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> S >> T; N = S.length(); H = T.length();
    S = " " + S; T = " " + T;
    vector<int> sf(26), tf(26);
    pw1[0] = 1; pw2[0] = 1;
    for (int i = 1; i <= N; i++) 
    {
        sf[S[i]-'a']++;
        pw1[i] = pw1[i-1]*B1%MOD;
        pw2[i] = pw2[i-1]*B2%MOD;
    }
    for (int i = 1; i <= H; i++) 
    {
        hsh1[i] = (hsh1[i-1]*B1%MOD+T[i])%MOD;
        hsh2[i] = (hsh2[i-1]*B2%MOD+T[i])%MOD;
        tf[T[i]-'a']++;
        if (i>N) tf[T[i-N]-'a']--;
        if (sf == tf) st.insert(substrHash(i-N+1, i));
    }
    cout << st.size() << "\n";
}