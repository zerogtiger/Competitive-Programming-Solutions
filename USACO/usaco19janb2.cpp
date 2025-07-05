#include "iostream"
#include <vector>
using namespace std;

int main()
{
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> V(N);
    for (auto& i : V)
        cin >> i;
    int cnt = 0, last = 0x3f3f3f3f;
    for (int i = N - 1; i >= 0; --i) {
        if (V[i] > last) {
            cout << N - cnt;
            return 0;
        }
        else {
            cnt++;
            last = V[i];
        }
    }
    cout << "0\n";
}
