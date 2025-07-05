#include "iostream"
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    vector<int> V(3);
    for (auto &i : V)
        cin >> i;
    sort(V.begin(), V.end());
    if (V[0] + 2 == V[2]) {
        cout << "0\n0\n";
        return 0;
    }
    if (V[0] + 2 == V[1] || V[1] + 2 == V[2]) {
        cout << "1\n";
    }
    else {
        cout << "2\n";
    }
    int mx = max(V[1] - V[0], V[2] - V[1]);
    cout << mx - 1<< "\n";
}
