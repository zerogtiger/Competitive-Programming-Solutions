#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;
int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<int, pair<string, int>>> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].first >> v[i].second.first >> v[i].second.second;
    }
    sort(v.begin(), v.end());
    int a[3] = {7, 7, 7}; // B M E
    bool p[3] = {false, false, false}; // B M E
    int ans = 0;
    for (auto &pp : v) {
        auto sec = pp.second;
        if (sec.first == "Bessie") {
            a[0] += sec.second;
        }
        else if (sec.first == "Mildred") {
            a[1] += sec.second;
        }
        else if (sec.first == "Elsie") {
            a[2] += sec.second;
        }
        int mx = max({a[0], a[1], a[2]});
        bool flag = false;
        for (int i =0; i < 3; ++i) {
            if (a[i] != mx && p[i]) {
                flag = true;
                p[i] = false;
            }
            else if (a[i] == mx && !p[i]) {
                flag = true;
                p[i] = true;
            }
        }
        ans += flag;
    }
    cout << ans << "\n";
}
