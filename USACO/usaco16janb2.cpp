#include "iostream"
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> V(N);
    for (auto& v : V)
        cin >> v;
    int ans = 0;
    sort(V.begin(), V.end());
    for (int s = 0; s < N; ++s) {
        int curr = 0;
        vector<int> R(N, -1);
        R[s] = 1;
        for (int f = s; f < N; ++f) {
            if (R[f] > 0) {
                curr++;
                for (int ff = f + 1; ff < N; ++ff) {
                    if (V[ff] <= V[f] + R[f] && R[ff] < 0) {
                        R[ff] = R[f] + 1;
                    }
                }
            }
        }
        R[s] = 1;
        for (int f = s; f >= 0; --f) {
            if (R[f] > 0) {
                curr++;
                for (int ff = f - 1; ff >=0; --ff) {
                    if (V[ff] >= V[f] - R[f] && R[ff] < 0) {
                        R[ff] = R[f] + 1;
                    }
                }
            }
        }
        ans = max(ans, curr - 1);
    }
    cout << ans << "\n";
}
