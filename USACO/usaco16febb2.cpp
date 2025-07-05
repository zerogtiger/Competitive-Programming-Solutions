#include "iostream"
#include <algorithm>
using namespace std;
int a[1002];
int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int N;
    cin >> N;
    int tot =0;
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        tot += a[i];
    }
    for (int i = 0; i < N; ++i) {
        int left = tot - a[i];
        int t_ans = 0;
        for (int j = 1; j < N; ++j) {
            t_ans += left;
            left -= a[(i + j)%N];
        }
        ans = min(ans, t_ans);
    }
    cout << ans << "\n";
    
    
}
