#include <iostream>

using namespace std;

const int MM = 101;
int a[MM];
int ans[MM];

int main() {
    freopen("shell.in", "r", stdin);

    int N;
    cin >> N;
    int mx = 0;
    for (int i = 1; i <= N; ++i) {
        a[i] = i;
    }
    for (int j = 0; j < N; ++j) {
        int p, q, g;
        cin >> p >> q >> g;
        swap(a[p], a[q]);
        ans[a[g]] ++;
        mx = max(ans[a[g]], mx);
    }
    freopen("shell.out", "w", stdout);
    std::cout << mx << "\n";
    // for (int i = 1; i <= N; ++i) {
    //     std::cout << ans[i] << ", ";
    // }
}
