#include "iostream"
#include "map"
#include "set"
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    int N, M, K;
    cin >> N >> M >> K;

    bool flag = true;
    set<int> mp;
    vector<int> order;
    map<int, int> order_i;
    for (int i = 0; i < M; ++i) {
        int tmp;
        cin >> tmp;
        mp.insert(tmp);
        order.push_back(tmp);
        order_i[tmp] = i;
        flag = flag || tmp == 1;
    }
    vector<int> ans(N + 2, -1);
    vector<pair<int, int>> used;
    int a = 0;
    int b = 0;
    while (K--) {
        cin >> a;
        cin >> b;
        ans[b] = a;
        if (mp.count(a)) {
            used.push_back({b, a});
        }
    }
    sort(used.begin(), used.end());
    int last = 0;
    for (auto& p : used) {
        int start = order_i[p.second];
        int idx = p.first - 1;
        for (int i = start - 1; i >= last; --i) {
            while (ans[idx] != -1)
                idx--;
            ans[idx] = order[i];
        }
        last = start + 1;
    }
    for (int i = 1; i < N + 2; ++i) {
        if (ans[i] == -1 || ans[i] == 1) {
            cout << i << "\n";
            return 0;
        }
    }
}
