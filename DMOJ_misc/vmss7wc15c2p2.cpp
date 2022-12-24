// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 25005, base = 151, base2 = 131, MOD = 1e9 + 7;

int N;
string S;
ll pw[MM], hshf[MM], hshb[MM], pw2[MM], hshf2[MM], hshb2[MM];
int cen, len;
bool isCentered;
bool check(int l, int r)
{
    return (hshf[l] - hshf[l - (r - l + 1)] * pw[r - l + 1] % MOD + MOD) % MOD ==
           (hshb[l] - hshb[r + 1] * pw[r - l + 1] % MOD + MOD) % MOD && 
           (hshf2[l] - hshf2[l - (r - l + 1)] * pw2[r - l + 1] % MOD + MOD) % MOD ==
           (hshb2[l] - hshb2[r + 1] * pw2[r - l + 1] % MOD + MOD) % MOD;
}
bool check(int ll, int lr, int r)
{
    return (hshf[ll] - hshf[ll - (r - lr + 1)] * pw[r - lr + 1] % MOD + MOD) % MOD ==
           (hshb[lr] - hshb[r + 1] * pw[r - lr + 1] % MOD + MOD) % MOD && 
           (hshf2[ll] - hshf2[ll - (r - lr + 1)] * pw2[r - lr + 1] % MOD + MOD) % MOD ==
           (hshb2[lr] - hshb2[r + 1] * pw2[r - lr + 1] % MOD + MOD) % MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin.ignore();
    cin >> S;
    pw[0] = 1;
    pw2[0] = 1;
    S = " " + S;
    for (int i = 1; i <= N; i++)
    {
        pw[i] = pw[i - 1] * base % MOD;
        pw2[i] = pw2[i - 1] * base2 % MOD;
        hshf[i] = (hshf[i - 1] * base % MOD + S[i]) % MOD;
        hshf2[i] = (hshf2[i - 1] * base2 % MOD + S[i]) % MOD;
        hshb[N - i + 1] = (hshb[N - i + 2] * base % MOD + S[N - i + 1]) % MOD;
        hshb2[N - i + 1] = (hshb2[N - i + 2] * base2 % MOD + S[N - i + 1]) % MOD;
    }
    for (int i = 1; i <= N; i++)
    {
        int c = i, l = i, r = min(N, 2 * i - 1), ans = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(c, mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if ((ans - c)*2 + 1 > len)
        {
            cen = c-(ans-c);
            len = (ans - c)*2 + 1;
        }
    }
    for (int i = 1; i < N; i++)
    {
        int cl = i, cr = i + 1, l = i + 1, r = min(N, 2 * i), ans = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(cl, cr, mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if ((ans-cr+1)*2 > len)
        {
            cen = cr-(ans-cr+1);
            len = (ans-cr+1)*2;
            isCentered = false;
        }
    }
    cout << S.substr(cen, len) << "\n" << len << "\n";
}