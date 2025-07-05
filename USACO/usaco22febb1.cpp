#include "iostream"
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> V(N + 2);
        int sum = 0;
        for (int i = 1; i <= N; ++i) {
            int tmp;
            cin >> tmp;
            V[i] += tmp;
            V[i + 1] = V[i];
            sum += tmp;
        }
        if (sum == 0) {
            cout << "0\n";
            continue;
        }
        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= sum; ++i) {
            if (sum % i == 0) {
                int curr = sum;
                for (int j = N; j >= 1; --j) {
                    if (V[j] == curr) {
                        curr -= i;
                    }
                }
                if (curr <= 0) {
                    ans = min(ans, N - sum/i);
                }
            }
        end:
            continue;
        }
        cout << ans << "\n";
    }
}
