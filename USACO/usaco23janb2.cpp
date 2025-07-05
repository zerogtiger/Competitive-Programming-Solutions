#include "iostream"
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int pre[104];
int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<pair<int, int>, int>> C(N);

    for (auto& p : C)
        cin >> p.first.first >> p.first.second >> p.second;

    sort(C.begin(), C.end());
    vector<pair<pair<int, int>, pair<int, int>>> A(M);
    for (auto& pp : A)
        cin >> pp.first.first >> pp.first.second >> pp.second.first >> pp.second.second;

    int ans = 0x3f3f3f3f;
    for (int m = 0; m < (1 << M); ++m) {
        memset(pre, 0, sizeof(pre));
        int cost = 0;
        for (int i = 0; i < m; ++i) {
            if (m & (1 << i)) {
                pre[A[i].first.first] += A[i].second.first;
                pre[A[i].first.second + 1] -= A[i].second.first;
                cost += A[i].second.second;
            }
        }
        for (int i = 1; i <= 100; ++i) {
            pre[i] += pre[i - 1];
        }
        bool flag = true;
        for (auto& p : C) {
            for (int i = p.first.first; i <= p.first.second; ++i) {
                if (pre[i] < p.second) {
                    flag = false;
                    goto end;
                }
            }
        }
end:
        if (flag) {
            ans = min(ans, cost);
        }
    }
    cout << ans << "\n";
}
