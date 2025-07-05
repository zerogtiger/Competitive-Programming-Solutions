#include <iostream>

using namespace std;

int m[3];
int c[3];

int main()
{
    freopen("mixmilk.in", "r", stdin);

    for (int i = 0; i < 3; ++i) {
        cin >> c[i] >> m[i];
    }
    for (int I = 0; I < 100; ++I) {
        int j = (I + 1) % 3;
        int i = I % 3;
        int amt = min(m[i], c[j] - m[j]);
        m[i] -= amt;
        m[j] += amt;
        // for (int i = 0; i < 3; ++i) {
        //     cout << m[i] << ",";
        // }
        // cout << "\n";
    }
    freopen("mixmilk.out", "w", stdout);
    for (int i = 0; i < 3; ++i) {
        cout << m[i] << "\n";
    }
}
