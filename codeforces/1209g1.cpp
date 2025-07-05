#include "iostream"
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> V(N);
    map<int, pair<int, int>> range;
    for (int I = 0; I < N; ++I) {
        cin >> V[I];
        if (range.count(V[I])) {
            range[V[I]].second = I;
        }
        else {
            range[V[I]] = {I, I};
        }
    }
    vector<pair<int, int>> pairs;
    for (auto& pp : range) {
        pairs.push_back(pp.second);
    }
    sort(pairs.begin(), pairs.end());
    vector<pair<int, int>> merged;
    int f = -1, l = -1;
    for (auto& p : pairs) {
        if (f == -1) {
            f = p.first;
            l = p.second;
        }
        else if (p.first < l) {
            l = max(l, p.second);
        }
        else {
            merged.push_back({f, l});
            f = p.first;
            l = p.second;
        }
    }
    if (f != -1) {
        merged.push_back({f, l});
    }
    int ans = 0;
    for (auto &p : merged) {
        map<int, int> cnt;
        int mx = 0;
        for (int i = p.first; i <= p.second; ++i) {
            cnt[V[i]]++;
            mx = max(mx, cnt[V[i]]);
        }
        ans += p.second - p.first + 1 - mx;
    }
    cout << ans << "\n";
}
