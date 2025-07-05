#include "iostream"
#include <string>
#include <vector>
using namespace std;
int main()
{
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    vector<pair<int, int>> V(26);
    for (int i = 1; i <= 52; ++i) {
        char tmp;
        cin >> tmp;
        if (V[tmp - 'A'].first == 0)
            V[tmp - 'A'].first = i;
        else 
            V[tmp - 'A'].second = i;
    }
    // for (auto &p : V) {
    //     cout << p.first << p.second << "\n";
    // }
    int ans = 0;
    for (int i = 0; i <= 25; ++i) {
        for (int j = i + 1; j <= 25; ++j) {
            auto f = min(V[i], V[j]);
            auto s = max(V[i], V[j]);
            if (f.second < s.second && f.second > s.first)
                ++ans;
        }
    }
    cout << ans << "\n";
}
