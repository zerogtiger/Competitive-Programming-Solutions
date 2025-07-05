#include "iostream"
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> V(N);
    for (auto &v : V) {
        cin >> v;
    }
    sort(V.begin(), V.end());
    int ans = 1;
    int last = V[0];
    for (auto &i : V) {
        if (last != i) {
            last = i;
            ans ++;
        }
    }
    cout << ans << "\n";
}
