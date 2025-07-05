#include "iostream"
using namespace std;

int main()
{
    int N;
    cin >> N;
    int even = 0, odd = 0;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        if (tmp % 2 == 0)
            even++;
        else
            odd++;
    }
    int ans = 0;
    if (even <= odd) {
        ans += even * 2;
        odd -= even;
        if (odd % 3 == 0) {
            ans += (odd / 3) * 2;
        }
        else if (odd %3 == 1) {
            ans += (odd / 3) * 2 - 1;
        }
        else {
            ans += (odd / 3) * 2 + 1;
        }
    }
    else if (even > odd) {
        ans += odd * 2 + 1;
    }
    cout << ans << "\n";
}
