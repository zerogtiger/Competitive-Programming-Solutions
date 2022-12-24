// Solution by zerogtiger on Github


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e6 + 5;

int N, M, C, a[MM];
deque<int> minq, maxq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> C;
    bool flag = false;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        while (!minq.empty() && minq.back() > a[i])
            minq.pop_back();
        while (!maxq.empty() && maxq.back() < a[i])
            maxq.pop_back();
        minq.push_back(a[i]);
        maxq.push_back(a[i]);
        if (i > M) 
        {
            if (minq.front() == a[i - M])
                minq.pop_front();
            if (maxq.front() == a[i - M])
                maxq.pop_front();
        }
        if (i >= M && maxq.front() - minq.front() <= C)
        {
            cout << (i - M + 1) << "\n";
            flag = true;
        }
    }
    if (!flag)
        cout << "NONE"
             << "\n";
}