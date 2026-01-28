#include "iostream"
#include "vector"
#include "algorithm"
typedef long long ll;
using namespace std;

const int MM = 1e5 + 3;
int dsu[MM];

int find(int curr) {
    if (dsu[curr] == curr) {
        return curr;
    }
    return dsu[curr] = find(dsu[curr]);
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        dsu[i] = i;
    }
    vector<tuple<int, int, ll>> V(M);
    for (auto& t : V)
    {
        cin >> get<1>(t) >> get<2>(t) >> get<0>(t);
    }
    sort(V.begin(), V.end());
    int cnt = 0;
    ll cost = 0;
    for (int i =0 ; i < M && cnt < N - 1; ++i)
    {
        auto t = V[i];
        if (find(get<1>(t)) == find(get<2>(t))) {
            continue;
        }
        else {
            dsu[find(get<1>(t))] = find(get<2>(t));
            cost += get<0>(t);
            ++cnt;
        }
    }
    if (cnt != N - 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << cost << "\n";
}
