#include "iostream"
#include "vector"
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> V(N);
        for (auto& p : V)
            cin >> p.first >> p.second;
        sort(V.begin(), V.end());
        int curr = 1;
        priority_queue<int> pq; // ending time
        int curr_idx = 0;
        while (curr_idx < N || !pq.empty()) {
            if (curr < V[curr_idx].first && pq.empty())
                curr = V[curr_idx].first;
            for (; curr_idx < N && V[curr_idx].first <= curr; ++curr_idx) {
                pq.push(-V[curr_idx].second);
            }
            if (curr > -pq.top()) {
                cout << "NO\n";
                goto end;
            }
            curr++;
            pq.pop();
        }
        cout << "YES\n";
    end:
        continue;
    }
}
