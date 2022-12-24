// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 3e6+5;

int N, K, a[MM]; deque<int> mini, maxi; ll ans;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> K;
    for (int r = 1, l = 1; r <= N; r++) 
    {
        cin >> a[r];
        while (!mini.empty() && mini.back() > a[r]) mini.pop_back();
        while (!maxi.empty() && maxi.back() < a[r]) maxi.pop_back();
        mini.push_back(a[r]);
        maxi.push_back(a[r]);
        while (maxi.front()-mini.front() > K) 
        {
            if (mini.front() == a[l]) mini.pop_front();
            if (maxi.front() == a[l]) maxi.pop_front();
            l++;
        }
        ans += (r-l+1);
    }
    cout << ans << "\n";
}