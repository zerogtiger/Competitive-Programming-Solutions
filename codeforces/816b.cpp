#include "iostream"
#include "vector"
using namespace std;

typedef long long ll;

const int MM = 2e5 + 5;
ll A[MM];
int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    while (N--) {
        int L, R;
        cin >> L >> R;
        ++A[L];
        --A[R + 1];
    }
    for (int i = 1; i < MM; ++i) {
        A[i] += A[i - 1];
    }
    for (int i = 1; i < MM; ++i) {
        if (A[i] >= K) {
            A[i] = 1;
        }
        else {
            A[i] = 0;
        }
        A[i] += A[i - 1];
    }
    while (Q--) {
        int a, b;
        cin >> a >> b;
        cout << A[b] - A[a - 1] << "\n";
    }
}
