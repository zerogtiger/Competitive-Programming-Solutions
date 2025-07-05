#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<pair<int, char>> V(N);
    int curr = 0;
    int ans = N;
    for (auto &p : V) {
        cin >> p.second >> p.first;
        if (p.second == 'G')
            ++curr;
    }
    sort(V.begin(), V.end());
    ans = min(ans, curr);
    for (auto &p : V) {
        if (p.second == 'G')
            curr--;
        else
            ++curr;
        ans = min(ans, curr);
    }
    cout << ans << "\n";
}
