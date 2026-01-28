#include "iostream"
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int main() {
    int N;
    cin >> N;
    vector<ll> V(N);
    for (auto &i : V)
        cin >> i;
    sort(V.begin(), V.end());
    ll accum = 0;
    for (auto &i : V){
        if (accum < i - 1) {
            cout << accum + 1 << "\n";
            return 0;
        }
        accum += i;
    }
    cout << accum + 1;
}
