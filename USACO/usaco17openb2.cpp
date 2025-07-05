#include "iostream"
#include "vector"
#include <algorithm>
#include <iterator>
#include <set>
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
    set<char> s, p;
    int ans = 0;
    for (int i = 0; i < M; ++i) {
        s.clear();
        p.clear();
        for (int j = 0; j < N; ++j) {
            s.insert(S[j][i]);
        }
        for (int j = 0; j < N; ++j) {
            p.insert(P[j][i]);
        }
        set<char> inter;
        set_intersection(s.begin(), s.end(), p.begin(), p.end(),
                         std::inserter(inter, inter.begin()));
        if (inter.size() == 0)
            ++ans;
    }
    cout << ans;
}
