#include "iostream"
#include "cmath"
using namespace std;

typedef long long ll;
int main() {
    ll N;
    cin >> N;
    ll ret = 0;
    for (ll i = 1; N / (ll) pow(5, i) > 0; ++i) {
        ret += (N / (ll) pow(5, i));
    }
    cout << ret << "\n";
}
