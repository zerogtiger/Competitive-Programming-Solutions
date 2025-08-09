#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

struct S {
    int x, y, t;
    bool operator<(const S& g) const { return t < g.t; }
};

bool cant_reach(S g1, S g2)
{
    long long dt = g1.t - g2.t;
    long long dx = g1.x - g2.x;
    long long dy = g1.y - g2.y;
    return dt * dt < dx * dx + dy * dy;
}

int main()
{
    int G, N;
    cin >> G >> N;
    vector<S> V(G);
    for (auto& s : V)
        cin >> s.x >> s.y >> s.t;
    sort(V.begin(), V.end());

    int ans = 0, NN = N;
    while (NN--) {
        int x, y, t;
        cin >> x >> y >> t;

        int u = upper_bound(V.begin(), V.end(), S{0, 0, t}) - V.begin();

        if (u < G) {
            if (cant_reach(S{x, y, t}, V[u]))
                continue;
        }

        if (u - 1 > 0) {
            if (cant_reach(S{x, y, t}, V[u - 1]))
                continue;
        }
        ans++;
    }
    cout << N - ans << "\n";
}
