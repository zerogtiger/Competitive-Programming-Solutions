#include "iostream"
#include <queue>
#include <map>
using namespace std;

int main() {
    priority_queue<pair<int, int>> pq; // ending (incr), beginning (decr)
    int K, N;
    cin >> N >> K;
    for (int i =0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        pq.push({-b, a});
    }
    map<int, int> curr; // current status
    curr[0] = K;
    int ans = 0;
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int start = top.second, end = -top.first;
        auto res = curr.lower_bound(-start);
        if (res == curr.end()) {
            continue;
        }
        else {
            ++ans;
            curr[res->first]--;
            if (curr[res->first] == 0)
                curr.erase(res->first);
            curr[-end]++;
        }
    }
    cout << ans << "\n";
}
