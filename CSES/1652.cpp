#include "iostream"
using namespace std;

int A[1004][1004];

int main()
{
    int N, Q;
    cin >> N >> Q;
    for (int j = 1; j <= N; ++j) {
        string S;
        cin >> S;
        for (int i = 1; i <= N; ++i) {
            A[j][i] = (S[i - 1] == '*' ? 1 : 0);
            A[j][i] += (A[j - 1][i] + A[j][i - 1] - A[j - 1][i - 1]);
        }
    }
    while (Q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << A[y2][x2] - A[y1 - 1][x2] - A[y2][x1 - 1] + A[y1 - 1][x1 - 1] << "\n";
    }
}
