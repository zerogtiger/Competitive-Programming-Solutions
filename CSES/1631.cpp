#include "iostream"
#include "vector"
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin>> N;
    ll sum = 0;
    ll mx = 0;
    for (int i =0; i < N; ++i) {
        ll k;
        cin >> k;
        mx = max(mx, k);
        sum += k;
    }
    sum -= mx;
    if (mx > sum) {
        cout << 2*mx << "\n";
    }
    else {
        cout << mx + sum << "\n";
    }
}
