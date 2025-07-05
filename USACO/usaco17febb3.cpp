#include "iostream"
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<int, int>> V(N);
    for (auto& p : V)
        cin >> p.first >> p.second;
    sort(V.begin(), V.end());
    int ans = 0;
    for (auto& p : V) {
        if (p.first > ans) {
            ans = (p.first + p.second);
        }
        else {
            ans += p.second;
        }
    }
    cout << ans << "\n";
}
