#include "iostream"
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main()
{
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int N;
    vector<tuple<int, int, int>> V; // arrival time, senority, time to eat
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, t;
        cin >> a >> t;
        V.push_back({a, i, t});
    }
    sort(V.begin(), V.end());
    int curr = 0; // last cow finish time
    int curr_idx = 0;
    int ret = 0;
    priority_queue<tuple<int, int, int>> pq; // senority, time of arrival, time to eat
    for (int i = 0; i < N; ++i) {
        if (curr_idx < N && curr < get<0>(V[curr_idx]) && pq.empty()) {
            int first_arrival = get<0>(V[curr_idx]);
            for (; curr_idx < N && get<0>(V[curr_idx]) == first_arrival; ++curr_idx)
                pq.push({-get<1>(V[curr_idx]), get<0>(V[curr_idx]), get<2>(V[curr_idx])});
        }
        else {
            for (; curr_idx < N && get<0>(V[curr_idx]) <= curr; ++curr_idx)
                pq.push({-get<1>(V[curr_idx]), get<0>(V[curr_idx]), get<2>(V[curr_idx])});
        }
        auto pp = pq.top();
        pq.pop();
        ret = max(ret, curr - get<1>(pp));
        curr = max(curr, get<1>(pp)) + get<2>(pp);
        // cout << get<0>(pp) << " " << curr << " " << pq.size() << "\n";

    }
    cout << ret << "\n";
}
