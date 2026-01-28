#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<pair<pair<int, int>, int>> V(N);
        for (int i = 0; i < N; ++i) {
            auto& pp = V[i];
            cin >> pp.first.first >> pp.first.second;
            if (pp.first.first > pp.first.second) {
                swap(pp.first.first, pp.first.second);
            }
            pp.second = i + 1;
        }
        sort(V.begin(), V.end());
        pair<int, int> mn = {-1, 0x3f3f3f3f};
        pair<int, int> curr_mn = {-1, 0x3f3f3f3f};
        int curr_mn_x_val = V[0].first.first;
        vector<int> ans(N, 0);
        for (int i = 0; i < N; ++i) {
            if (V[i].first.first != curr_mn_x_val) {
                curr_mn_x_val = V[i].first.first;
                if (curr_mn.second < mn.second) {
                    mn.second = curr_mn.second;
                    mn.first = curr_mn.first;
                }
            }
            if (V[i].first.second <= mn.second) {
                ans[V[i].second - 1] = -1;
            }
            else {
                ans[V[i].second - 1] = mn.first;
            }
            if (curr_mn.second > V[i].first.second) {
                curr_mn.second = V[i].first.second;
                curr_mn.first = V[i].second;
            }
        }
        for (int i = 0; i < N; ++i) {
            cout << ans[i] << (i == N - 1 ? "\n" : " ");
        }
    }
}
