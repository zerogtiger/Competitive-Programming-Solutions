#include "iostream"
#include "vector"
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> dp(N + 1, 0x3f3f3f3f);
    for (int i = 0; i <= N; ++i) {
        if (i == 0) {
            dp[i] = 0;
        }
        if (i < 10) {
            dp[i] = 1;
        }
        else {
            int curr = i;
            while (curr != 0) {
                int dig = curr % 10;
                if (dig != 0) {
                    dp[i] = min(dp[i], dp[i - dig] + 1);
                }
                curr /= 10;
            }
        }
    }
    cout << dp[N] << "\n";
}
