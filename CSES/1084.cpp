#include "iostream"
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    vector<int> B(M);
    for (auto& i : A)
        cin >> i;
    for (auto& i : B)
        cin >> i;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int b = 0;
    int ans = 0;
    for (auto& i : A) {
        for (; b < M && B[b] < i - K; ++b) {
        }
        if (b < M && B[b] <= i + K){
            ++b;
            ans++;
        }
    }
    cout << ans << "\n";
}
