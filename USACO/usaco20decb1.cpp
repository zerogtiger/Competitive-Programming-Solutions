#include "iostream"
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> V(N);
    for (auto &i : V)
        cin >> i;
    sort(V.begin(), V.end());
    long long ans = 0, tui = 0;
    for (int i = 0; i < N; ++i) {
        long long val = (long long) V[i] * (long long) (N - i);
        if (val > ans) {
            ans = val;
            tui = V[i];
        }
    }
    cout << ans << " " << tui << "\n";
}
