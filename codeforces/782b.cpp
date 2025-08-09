#include "iostream"
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

int N;
vector<pair<double, double>> V;

int main()
{
    cin >> N;
    V.resize(N);
    for (auto& p : V)
        cin >> p.first;
    for (auto& p : V)
        cin >> p.second;
    sort(V.begin(), V.end());
    double lo = 0, hi = 1e9;
    double ans = 1e10;
    while (lo < hi && hi - lo > 1e-7) {
        double mid = lo + (hi - lo) / 2;
        double mtime = 0, mlft = 0, mrht = 0;
        for (auto& p : V) {
            mtime = max(mtime, abs(mid - p.first) / p.second);
            if (p.first <= mid)
                mlft = max(mlft, abs(mid - p.first) / p.second);
            else
                mrht = max(mrht, abs(mid - p.first) / p.second);
        }
        ans = min(ans, mtime);
        if (mlft > mrht)
            hi = mid;
        else
            lo = mid;
    }
    printf("%0.9f\n", ans);
}
