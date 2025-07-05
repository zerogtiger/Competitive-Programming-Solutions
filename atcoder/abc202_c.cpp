#include "iostream"
#include <map>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    map<int, int> A;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        A[tmp]++;
    }
    vector<int> B(N);
    for (auto &i : B)
        cin >> i;

    long long ans = 0;
    while (N--) {
        int c;
        cin >> c;
        ans += A[B[c - 1]];
    }
    cout << ans << "\n";
}
