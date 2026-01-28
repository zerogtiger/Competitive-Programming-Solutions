// Bellman Ford + track parent

#include "iostream"
#include "vector"
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;
const int MM = 2505;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int par[MM];
ll dist[MM];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, ll>> V;
    for (int i = 0; i < M; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        V.emplace_back(a, b, c);
    }
    dist[1] = 0;
    int start = 0;
    for (int i = 1; i <= N; ++i) {
        for (auto& e : V) {
            if (dist[get<0>(e)] < inf && dist[get<1>(e)] > dist[get<0>(e)] + get<2>(e)) {
                dist[get<1>(e)] = dist[get<0>(e)] + get<2>(e);
                par[get<1>(e)] = get<0>(e);
                if (i == N && start == 0) {
                    start = get<0>(e);
                }
            }
        }
    }
    if (start != 0) {
        vector<int> tmp;
        set<int> st;
        cout << "YES\n";
        tmp.push_back(start);
        st.insert(start);
        int curr = par[start];
        while (!st.count(curr)) {
            tmp.push_back(curr);
            st.insert(curr);
            curr = par[curr];
        }
        reverse(tmp.begin(), tmp.end());
        cout << curr << " ";
        for (auto &i : tmp)  {
            cout << i << " ";
            if (i == curr) {
                break;
            }
        }
        return 0;
    }
    cout << "NO\n";
}
