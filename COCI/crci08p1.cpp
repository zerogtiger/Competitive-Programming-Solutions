//Solution by OneZeroGuru on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e5+5;

string s; 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    int count = 0, curr = 0;
    for(auto c : s)
    {
        if (isupper(c)) {count += (4-curr%4)%4; curr = 1;}
        else curr++;
    }
    cout << count << endl;
}
