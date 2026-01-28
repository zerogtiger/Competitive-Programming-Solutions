#include "iostream"
#include "vector"
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> V(100 + 2), W(100 + 2);
    V[0] = 0;
    V[101] = 0;
    long long ans = 1;
    int curr;
    for (int i = 0; i < N; ++i) {
        cin >> curr;
        if (curr == 0 && i == 0) {
            for (int v = 1; v <= M; ++v) {
                V[v] = 1;
            }
        }
        else if (i == 0) {
            for (int v = 1; v <= M; ++v) {
                V[v] = 0;
            }
            V[curr] = 1;
        }
        else if (curr != 0) {
            for (int v = 1; v <= M; ++v) {
                if (v < curr - 1 || v > curr + 1)
                    V[v] = 0;
            }
            long long tot = 0;
            for (int v = 1; v <= M; ++v) {
                tot = (tot + V[v]) % mod;
            }
            V[curr] = 1;
            V[curr - 1] = V[curr + 1] = 0;
            ans = (tot * ans) % mod;
        }
        else {
            for (int v = 1; v <= M; ++v) {
                W[v] = ((V[v] + V[v - 1]) % mod + V[v + 1]) % mod;
            }
            swap(V, W);
        }
    }
    if (curr == 0) {
        long long tot = 0;
        for (int v = 1; v <= M; ++v) {
            tot = (tot + V[v]) % mod;
        }
        ans = (tot * ans) % mod;
    }
    cout << ans << "\n";
}
