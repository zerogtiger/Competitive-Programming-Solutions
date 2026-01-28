#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> V(N);
    for (auto &i : V)
        cin >>i;
    sort(V.begin(), V.end());
    int ans = 0;
    for (int i =0; i < N; ++i) {
        if (X < V[i]) {
            cout << ans << "\n";
            return 0;
        }
        X -= V[i];
        ans ++;
    }
    cout << N;
}
