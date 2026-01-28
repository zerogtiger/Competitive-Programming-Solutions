#include "iostream"
#include "vector"
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;

const int MM = 4e5 + 7;
int bit[MM];
void update(int pos, int val)
{
    for (int i = pos; i < MM; i += (i & -i))
        bit[i] += val;
}

int query(int pos)
{
    int ret = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        ret += bit[i];
    // cout << "(" << pos << "," << ret << ")\n";
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // coordinate compression
    int N;
    cin >> N;
    vector<pair<pair<int, int>, int>> V(N); // -y, x
    set<int> X;
    for (int i = 0; i < N; ++i) {
        cin >> V[i].first.second >> V[i].first.first;
        V[i].second = i;
        X.insert(V[i].first.second);
        X.insert(V[i].first.first);
        V[i].first.first *= -1;
    }
    map<int, int> xx;
    for (auto& i : X) {
        xx[i] = xx.size() + 1;
    }
    sort(V.begin(), V.end());
    vector<int> contains(N);
    vector<int> contained(N);
    for (int i = N - 1; i >= 0; --i) {
        contains[V[i].second] = query(xx[-V[i].first.first]) - query(xx[V[i].first.second] - 1);
        update(xx[V[i].first.second], 1);
    }
    // for (int i =0 ; i < 2*N; ++i) {
    //     cout << bit[i] << " ";
    // }
    // cout << "\n";
    memset(bit, 0, sizeof(bit));
    for (int i = 0; i < N; ++i) {
        contained[V[i].second] = query(xx[V[i].first.second]);
        update(xx[V[i].first.second], 1);
    }
    for (auto &i : contains) {
        cout << (i > 0) << " ";
    }
    cout << "\n";
    for (auto &i : contained) {
        cout << (i > 0) << " ";
    }
}
