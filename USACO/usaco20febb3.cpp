#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

int main()
{
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<vector<int>> per_index(N + 1);
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j)
            A[j] = j;
        do {
            per_index[i].push_back(A[i]);
            reverse(A.begin() + a, A.begin() + b + 1);
            reverse(A.begin() + c, A.begin() + d + 1);
        } while (A[i] != i);
    }
    for (int i = 1; i <= N; ++i) {
        cout << per_index[i][K % (int) per_index[i].size()] << "\n";
    }
}
