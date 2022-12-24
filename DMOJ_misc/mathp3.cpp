// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 2e5+5;

int N, a[MM];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N;
    bool flag;
    for (int i = 1; i <= N; i++) 
    {
        cin >> a[i];
        if (i == 1) flag = (a[i] == 1);
        flag = flag && !(a[i] > i || a[i] < a[i-1] || a[i] > a[i-1]+1);
    }
    if (!flag) cout << -1 << "\n";
    else{
        vector<int> v;
        int cnt = 0;
        a[N+1]= 0x3f3f3f3f;
        for (int i = 1; i <= N+1; i++) 
        {
            if (a[i] != a[i-1]) {v.push_back(cnt);}
            cnt++;
        }
        for (int i = 1; i < v.size(); i++) 
        {
            for (int j = v[i]; j > v[i-1]; j--) 
            {
                cout << (i == 1 && j == v[i]? "" : " ") << j;
            }
        }
        cout << "\n";
    }
}