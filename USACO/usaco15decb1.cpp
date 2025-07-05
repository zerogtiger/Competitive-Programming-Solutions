#include "iostream"
using namespace std;
int main()
{
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > c) {
        swap(a, c);
        swap(b, d);
    }
    if (b > c) {
        cout << max(b, d) - a << "\n";
    }
    else {
        cout << b - a - (c - d) << "\n";
    }
}
