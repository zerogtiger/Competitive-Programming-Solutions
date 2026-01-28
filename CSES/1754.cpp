#include "iostream"
using namespace std;

typedef long long  ll;
int main() {
    int T; 
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a >> b;
        ll p = (2 * a - b);
        ll q = (2 * b - a);
        if (p % 3 == 0 && p >= 0  && q % 3 == 0 && q >= 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
