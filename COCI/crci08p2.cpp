// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e5 + 5;

int r, n, f[53][3];
string s;
unordered_map<char, int> m = {{'R', 0}, {'P', 1}, {'S', 2}};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> s >> n;
    for (int i = 1; i <= n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 1; j <= r; j++)
        {
            f[j][m[temp[j - 1]]]++;
        }
    }
    int act = 0, maxi = 0;
    for (int i = 1; i <= r; i++)
    {
        act += 2 * f[i][(m[s[i - 1]] + 2) % 3] + f[i][m[s[i - 1]]];
        maxi += max(max(2 * f[i][(0 + 2) % 3] + f[i][0],
                        2 * f[i][(1 + 2) % 3] + f[i][1]),
                        2 * f[i][(2 + 2) % 3] + f[i][2]);
    }
    cout << act << endl;
    cout << maxi << endl;
}
