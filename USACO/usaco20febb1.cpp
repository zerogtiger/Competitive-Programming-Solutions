#include "iostream"
#include <vector>
using namespace std;

int main()
{
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<int, int>> V(N);
    for (auto& p : V)
        cin >> p.first >> p.second;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                if (V[i].first == V[j].first && V[j].second == V[k].second)
                    ans = max(ans, abs((V[j].first - V[k].first) * (V[i].second - V[j].second)));
            }
        }
    }
    cout << ans << "\n";
}
