#include "iostream"
#include "vector"
#include <algorithm>
#include <iterator>
#include <set>
#include <tuple>
using namespace std;
int main()
{
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    vector<string> S(N), P(N);
    for (auto& s : S)
        cin >> s;
    for (auto& s : P)
        cin >> s;
    set<tuple<char, char, char>> ss, ps;
    int ans = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = i + 1; j < M; ++j) {
            for (int k = j + 1; k < M; ++k) {
                ss.clear(), ps.clear();
                for (auto &s : S) {
                    ss.insert(tie(s[i], s[j], s[k]));
                }
                for (auto &s : P) {
                    ps.insert(tie(s[i], s[j], s[k]));
                }
                set<tuple<char, char, char>> inter;
                set_intersection(ss.begin(), ss.end(), ps.begin(), ps.end(), inserter(inter, inter.begin()));
                ans += (inter.size() == 0? 1 : 0);
            }
        }
    }
    cout << ans << "\n";
}
