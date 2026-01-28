#include "iostream"
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    priority_queue<pair<int, int>> pq;
    pq.push({-0x3f3f3f3f, 0});
    int N;
    cin >>N ;
    int room_count = 0;
    vector<int> out(N);
    vector<pair<pair<int, int>, int>> V(N);
    for (int i =0 ; i < N; ++i) {
        auto &p = V[i];
        cin >> p.first.first >> p.first.second;
        p.second = i;
    }
    sort(V.begin(), V.end());
    for (int i =0; i < N; ++i) {
        int start = V[i].first.first, end = V[i].first.second;
        if (-pq.top().first >= start) {
            // cout << pq.top().first << "\n";
            room_count ++;
            out[V[i].second]= room_count;
            pq.push({-end, room_count});
        }
        else {
            auto p = pq.top();
            pq.pop();
            pq.push({-end, p.second});
            out[V[i].second]= p.second;
        }
    }
    cout << room_count << "\n";
    for (auto & i : out)
        cout << i << " ";
}
