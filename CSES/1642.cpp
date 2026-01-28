#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, X;
    cin >> N >> X;
    vector<pair<ll, int>> V(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i].first;
        V[i].second = i + 1;
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            ll tmp = V[i].first + V[j].first;
            int l = j + 1, r = N - 1;
            while (l < r) {
                if (tmp + V[l].first + V[r].first == X) {
                    cout << V[i].second << " " << V[j].second << " " << V[l].second << " "
                         << V[r].second << "\n";
                    return 0;
                }
                else if (tmp + V[l].first + V[r].first < X) {
                    ++l;
                }
                else
                    --r;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
