#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

const int MM = 1e6 + 3;
int A[MM];
int main() {
    int N, K;
    cin >> N >> K;
    while (K--) {
        int a, b;
        cin >> a >> b;
        A[a] ++;
        A[b + 1]--;
    }
    for (int i =1; i <= N; ++i) {
        A[i] += A[i - 1];
    }
    std::nth_element(A, A+ N/2, A + N);
    cout << A[N/2] << "\n";
}
