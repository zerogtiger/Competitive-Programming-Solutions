// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 2e6 + 5, base1 = 131, base2 = 10007, MOD = 1e9 + 7;

int N, M, ans;
unordered_map<ll, int> dp;
string s;
ll hsh1[MM], hsh2[MM], pw1[MM], pw2[MM];

bool check(int n)
{
    return ((hsh1[n] - hsh1[0] * pw1[n]%MOD+MOD)%MOD << 16 | (hsh2[n] - hsh2[0] * pw2[n]%MOD+MOD)%MOD) ==
           ((hsh1[M] - hsh1[M - n] * pw1[n]%MOD+MOD)%MOD << 16 | (hsh2[M] - hsh2[M - n] * pw2[n]%MOD+MOD)%MOD);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin.ignore();
    pw1[0] = 1;
    pw2[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        cin >> s;
        M = s.length();
        hsh1[0] = hsh2[0] = 0;
        s = " " + s;
        for (int j = 1; j <= M; j++)
        {
            pw1[j] = pw1[j - 1] * base1 % MOD;
            pw2[j] = pw2[j - 1] * base2 % MOD;
            hsh1[j] = (hsh1[j - 1] * base1 % MOD + s[j]) % MOD;
            hsh2[j] = (hsh2[j - 1] * base2 % MOD + s[j]) % MOD;
        }
        for (int j = 1; j <= M; j++)
        {
            if (check(j))
            {
                dp[(hsh1[M] << 16 | hsh2[M])] = max(dp[(hsh1[M] << 16 | hsh2[M])], dp[((hsh1[j] - hsh1[0] * pw1[j]%MOD+MOD)%MOD << 16 | (hsh2[j] - hsh2[0] * pw2[j]%MOD+MOD)%MOD)]);
            }
        }
        dp[(hsh1[M] << 16 | hsh2[M])]++;
        ans = max(dp[(hsh1[M] << 16 | hsh2[M])], ans);
    }
    cout << ans << "\n";
}