#include "iostream"
#include <queue>
using namespace std;

int main()
{
    int N;
    cin >> N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
        enter; // start, end
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
        exit; // end, start
    for (int i = 0; i < N; ++i) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        enter.push(p);
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (enter.empty()) {
            break;
        }
        else {
            while (!exit.empty() && exit.top().first < enter.top().first) {
                exit.pop();
            }
            auto& p = enter.top();
            exit.push({p.second, p.first});
            enter.pop();
        }
        ans = max((size_t) ans, exit.size());
    }
    cout << ans << "\n";
}
