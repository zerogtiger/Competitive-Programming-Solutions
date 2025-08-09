#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

int main()
{
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int N, Q;
    cin >> N >> Q;
    vector<int> V(N);
    for (auto& i : V)
        cin >> i;
    sort(V.begin(), V.end());
    while (Q--) {
        int A, B;
        cin >> A >> B;
        cout << (upper_bound(V.begin(), V.end(), B) - V.begin()) - (lower_bound(V.begin(), V.end(), A) - V.begin()) << "\n";
    }
}
