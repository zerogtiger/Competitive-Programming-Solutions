#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int main()
{
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    int N;
    cin >> N;
    if (N == 1) {
        cout << "1\n";
        return 0;
    }
    vector<int> V(N + 2);
    V[0] = -0x3f3f3f3f;
    V[N + 1] = 0x3f3f3f3f;
    for (int i = 1; i <= N; ++i)
        cin >> V[i];
    sort(V.begin(), V.end());
    vector<int> marking(N + 2);
    for (int i = 1; i <= N; ++i) {
        if (V[i] - V[i - 1] <= V[i + 1] - V[i]) {
            marking[i] = -1;
        }
        else {
            marking[i] = 1;
        }
    }
    marking[0] = -1;
    marking[N + 1] = 1;
    // for (int i = 1; i <= N; ++i) {
    //     cout << marking[i] << ", ";
    // }
    int l = 1, r = 1;
    vector<pair<int, int>> segments;
    for (int i = 1; i <= N; ++i) {
        r = i;
        if (marking[i] == -1 && marking[i + 1] == 1) {
            segments.push_back({l, i});
            r = l = i + 1;
        }
    }
    int ans = 0;
    for (auto& p : segments) {
        // cout << p.first << " " << p.second << "\n";
        if (p.second - p.first + 1 <= 3)
            ans++;
        else if (marking[p.first + 1] == -1 || marking[p.second - 1] == 1)
            ans++;
        else
            ans += 2;
    }
    cout << ans << "\n";
}
