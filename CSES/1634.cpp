#include "iostream"
#include <cstring>
#include <vector>
using namespace std;

vector<int> V;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // memset(mp, -1, sizeof(mp));
    int N, X;
    cin >> N >> X;
    for (int i = 0; i <N;++i)  {
        int c;
        cin >> c;
        V.push_back(c);
    }
    vector<int> dp(X+1, 0x3f3f3f3f);
    for (int i =0 ; i <= X; ++i) {
        if (i == 0) 
            dp[i] = 0;
        else {
            int mn = 0x3f3f3f3f;
            for (auto &j : V) {
                if (i - j < 0) {
                    continue;
                }
                mn = min(mn, dp[i - j]);
            }
            dp[i] = (mn == 0x3f3f3f3f ? mn : mn + 1);
        }
    }
    cout << (dp[X] == 0x3f3f3f3f ? -1 : dp[X]);
}
