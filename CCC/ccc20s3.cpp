// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 2e5 + 5, MOD = 1e9 + 7, B = 131, B2 = 10007;

string N, H;
deque<int> dq;
ll hsh[MM], pw, hsh2[MM], pw2;
set<ll> s;
int ncnt[26], ccnt[26];

ll modPow(int b, int p)
{
    if (p == 0)
        return 1;
    ll temp = modPow(b, p / 2);
    if (p % 2 == 1)
        return (temp * temp % MOD * b) % MOD;
    else
        return (temp * temp) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> H;
    int n = N.length(), h = H.length();
    N = " " + N;
    H = " " + H;
    pw = modPow(B, n);
    pw2 = modPow(B2, n);
    for (int i = 1; i <= n; i++)
    {
        ncnt[N[i] - 'a']++;
    }

    hsh[1] = H[1];
    hsh2[1] = H[1];
    for (int i = 1; i < h; i++)
    {
         hsh[i + 1] = (hsh[i] *   B % MOD + H[i+1] + MOD) % MOD;
        hsh2[i + 1] = (hsh2[i] * B2 % MOD + H[i+1] + MOD) % MOD;
    }

    for (int i = 1; i <= h; i++)
    {
        dq.push_back(H[i] - 'a');
        ccnt[H[i] - 'a']++;
        if (i >= N.length())
        {
            ccnt[dq.front()]--;
            dq.pop_front();
        }
        bool flag = true;
        for (int j = 0; j < 26; j++)
        {
            flag = flag && (ccnt[j] == ncnt[j]);
        }
        if (flag)
        {
            ll tmp1 = (hsh[i] - (hsh[i - n] * pw) % MOD + MOD) % MOD;
            ll tmp2 = (hsh2[i] - (hsh2[i - n] * pw2) % MOD + MOD) % MOD;
            s.insert((tmp1<<32)|tmp2);
        }
    }
    cout << s.size() << "\n";
}