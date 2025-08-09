#include "iostream"
#include "vector"
using namespace std;

typedef long long ll;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> V(N);
    for (auto &i : V) 
        cin >> i;
    ll sum = 0;
    int ans = 0;
    for (int l = 0, r = 0; r < N; ++r) {
        sum += V[r];
        while (sum > T) {
            sum -= V[l];
            ++l;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << "\n";
}
