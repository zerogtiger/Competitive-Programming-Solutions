#include "iostream"
#include <vector>
using namespace std;

int main()
{
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> V(N);
    for (auto& i : V)
        cin >> i;
    vector<int> ans(N);
    if (V[0] > 0) {
        cout << "-1\n";
        return 0;
    }
    ans[0] = 1;
    for (int i = 1; i < N; ++i) {
        if (V[i] >= 0) {
            if (i - V[i] < 0) {
                cout << "-1\n";
                return 0;
            }
            ans[i - V[i]] = 1;
            for (int j = i - V[i] + 1; j <= i; ++j) {
                ans[j] = -1;
                if (V[j] > j - (i - V[i])) {
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }
    int mn = 0, mx = 0;
    for (auto& i : ans) {
        mn += (i == 1);
        mx += (i >= 0);
    }
    cout << mn << " " << mx << "\n";
}
