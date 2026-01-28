#include "iostream"
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;
ll N;
ll fun(ll pow)
{
    if (pow == 1) {
        return 2;
    }
    if (pow == 0) {
        return 1;
    }
    else {
        ll res = fun(pow / 2);
        res = (res * res) % mod;
        if (pow % 2 == 1)
            res = (res * 2) % mod;
        return res;
    }
}
int main()
{
    cin >> N;
    cout << fun(N) << "\n";
}
