#include "iostream"
#include <cstdio>
using namespace std;

int A[12][12];
int main()
{
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char tmp;
            cin >> tmp;
            A[i][j] = tmp - '0';
        }
    }
    int ans = 0;
    for (int n = N - 1; n >= 0; --n) {
        for (int r = n; r >= 0; --r) {
            if (A[r][n] == 1) {
                ++ans;
                for (int i = 0; i <= r; ++i) {
                    for (int j = 0; j <= n; ++j) {
                        A[i][j] = 1 - A[i][j];
                    }
                }
            }
        }
        for (int c = n; c >= 0; --c) {
            if (A[n][c] == 1) {
                ++ans;
                for (int i = 0; i <= n; ++i) {
                    for (int j = 0; j <= c; ++j) {
                        A[i][j] = 1 - A[i][j];
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}
