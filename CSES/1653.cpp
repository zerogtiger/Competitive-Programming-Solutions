// bit mask + memoisation

#include "iostream"
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;

int N, X;
int dp[1 << 20];
int curr_weight[1 << 20];
vector<ll> V;

pair<int, int> fun(int mask) // rides used, weight remaining
{
    if (mask == (1 << N) - 1) {
        return {0, 0};
    }
    if (dp[mask] != inf) {
        return {dp[mask], curr_weight[mask]};
    }
    else {
        int mn = inf;
        int weight = 0;
        for (int i = 0; i < N; ++i) {
            if ((mask & (1 << i)) == 0) {
                auto res = fun(mask | (1 << i));
                if (res.second + V[i] > X) {
                    res.second = min(V[i], (ll) res.second);
                    res.first++;
                }
                else {
                    res.second += V[i];
                }
                if (res.first < mn) {
                    mn = res.first;
                    weight = res.second;
                }
                else if (res.first == mn) {
                    weight = min(weight, res.second);
                }
            }
        }
        dp[mask] = mn;
        curr_weight[mask] = weight;
        return {mn, weight};
    }
}

int main()
{
    cin >> N >> X;
    for (int i = 0; i < N; ++i) {
        int w;
        cin >> w;
        V.push_back(w);
    }
    memset(dp, inf, sizeof(dp));
    memset(curr_weight, inf, sizeof(curr_weight));
    cout << fun(0).first + 1 << "\n";
}
