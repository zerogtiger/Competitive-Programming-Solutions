#include "iostream"
#include "vector"
#include <map>
using namespace std;

int a[13][13];
int main()
{
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> V(10, -1);
    vector<pair<pair<int, int>, pair<int, int>>> mp(10, {{0x3f3f3f3f, 0x3f3f3f3f}, {-1, -1}});

    // cout << "N: " << N << "\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char tmp;
            cin >> tmp;
            a[i][j] = tmp - '0';
            V[a[i][j]] = 1;
            mp[a[i][j]].first = {min(mp[a[i][j]].first.first, i),
                                 min(mp[a[i][j]].first.second, j)};
            mp[a[i][j]].second = {max(mp[a[i][j]].second.first, i),
                                  max(mp[a[i][j]].second.second, j)};
        }
    }
    // for (auto &pppp: mp) {
    //     cout << pppp.first.first << ", " << pppp.first.second << ", " << pppp.second.first << ", " << pppp.second.second << "\n";
    // }
    vector<vector<int>> par(10);
    for (int i = 1; i < 10; ++i) {
        if (V[i] < 0) {
            continue;
        }
        auto mn = mp[i].first;
        auto mx = mp[i].second;
        for (int r = mn.first; r <= mx.first; ++r) {
            for (int c = mn.second; c <= mx.second; ++c) {
                if (a[r][c] != i)
                    par[a[r][c]].push_back(i);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < 10; ++i) {
        if (V[i] >= 0 && par[i].empty())  {
            // cout << i << "\n";
            ans++;
        }
    }
    cout << ans << "\n";
}

