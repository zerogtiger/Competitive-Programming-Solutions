#include "iostream"
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> V(2 * N);
    for (auto& v : V)
        cin >> v;
    sort(V.begin(), V.end());
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < 2 * N; ++i) {
        for (int j = i + 1; j < 2 * N; ++j) {
            int tmp = 0;
            int last = -1;
            for (int k = 0; k < 2*N; ++k) {
                if (k == i || k == j) {
                    continue;
                }
                if (last < 0) {
                    last = V[k];
                }
                else {
                    tmp += abs(V[k] - last);
                    last = -1;
                }
            }
            ans = min(ans, tmp);
        }
    }
    cout << ans << "\n";
}
