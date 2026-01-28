#include "iostream"
using namespace std;

typedef long long ll;
int main()
{
    int T;
    cin >> T;
    while (T--) {
        ll R, C;
        cin >> R >> C;
        ll cycle = max(R, C);
        if (cycle % 2 == 0) {
            if (R >= C) {
                cout << cycle * cycle - (C - 1);
            }
            else {
                cout << cycle * cycle - cycle - (cycle - R - 1);
            }
        }
        else {
            if (R < C) {
                cout << cycle * cycle - (R - 1);
            }
            else {
                cout << cycle * cycle - cycle - (cycle - C - 1);
            }
        }
        cout << "\n";
    }
}
