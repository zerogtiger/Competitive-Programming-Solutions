#include "iostream"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N, A, B;
        cin >> N >> A >> B;
        if (A + B > N || (A + B == N && (A == 0 || B == 0)) || (A == 0 && B != 0) ||
            (B == 0 && A != 0)) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            int num_ties = N - A - B, num_wins = A + B;
            for (int i = A - 1; i >= 0; --i) {
                cout << num_wins - i << " ";
            }
            for (int i = 1; i <= B; ++i) {
                cout << i << " ";
            }
            for (int i = 1; i <= num_ties; ++i) {
                cout << num_wins + i << " ";
            }
            cout << "\n";
            for (int i = 1; i <= N; ++i) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
}
