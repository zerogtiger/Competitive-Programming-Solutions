#include "iostream"
#include "vector"
using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    vector<int> dp(X + 1);
    vector<pair<int, int>> B(N);
    for (auto& p : B) {
        cin >> p.first;
    }
    for (auto& p : B) {
        cin >> p.second;
    }
    for (auto& p : B) {
        for (int i = X; i >= p.first; --i) {
            dp[i] = max(dp[i], dp[i - p.first] + p.second);
        }
    }
    cout << dp[X] << "\n";
}
