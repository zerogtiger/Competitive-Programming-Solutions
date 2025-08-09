#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MM = 2e5 + 5;

int A[MM];

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> V(N);
    for (auto &i : V) {
        cin >> i;
    }
    sort(V.begin(), V.end());
    while (Q--) {
        int L, R;
        cin >> L >> R;
        A[L]++;
        A[R + 1]--;
    }
    for (int i = 1; i <= N; ++i) {
        A[i] += A[i - 1];
    }
    sort(A + 1, A + N + 1);
    long long ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += (long long) A[i] * V[i - 1];
    }
    cout << ans << "\n";

}
