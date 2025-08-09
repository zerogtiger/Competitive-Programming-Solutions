#include "iostream"
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long long > V(N + 2);
    V[0] = 0;
    for (int i = 1; i <= N; ++i){ 
        cin >> V[i];
        V[i] += V[i - 1];
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << V[r] - V[l] << "\n";
    }
}
