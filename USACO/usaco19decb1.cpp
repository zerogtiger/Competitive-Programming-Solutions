#include "iostream"

using namespace std;

int ans[23][23], a[23];
int main()
{
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int K, N;
    cin >> K >> N;
    bool init = true;
    int n_cons = (N*(N - 1))/2;
    while (K--) {
        for (int i = 0; i < N; ++i) {
            int tmp;
            cin >> tmp;
            a[tmp] = i; // cow to place
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                if (init) {
                    ans[i][j] = (a[i] > a[j]);
                }
                else if (ans[i][j] != -1 && (ans[i][j] != (a[i] > a[j]))) {
                    // cout << i << "
                    ans[i][j] = -1;
                    --n_cons;
                }
            }
        }
        init = false;
    }
    cout << n_cons << "\n";
}
