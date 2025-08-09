#include "iostream"
#include "vector"
using namespace std;

typedef long long ll;
const int MM = 1e5 + 4;
ll marking[MM];
ll out[MM];
ll delta[MM];
int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i)
        cin >> out[i];
    vector<pair<pair<ll, ll>, ll>> op(M + 1);
    for (int i = 1; i <= M; ++i) {
        cin >> op[i].first.first >> op[i].first.second >> op[i].second;
    }
    while (K--) {
        ll a, b;
        cin >> a >> b;
        marking[a]++;
        marking[b + 1]--;
    }
    int running = 0;
    for (int i = 1; i <= M; ++i) {
        running += marking[i];
        delta[op[i].first.first] += op[i].second * running;
        delta[op[i].first.second + 1] -= op[i].second * running;
    }
    for (int i =1; i <= N; ++i) {
        delta[i] += delta[i - 1];
        cout << delta[i] + out[i] << (i == N ? "\n" : " ");
    }
}
