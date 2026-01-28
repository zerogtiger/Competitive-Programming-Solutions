#include "iostream"
#include <cstring>
using namespace std;

typedef long long ll;

int a[103][103];
int mex[204];

int main()
{
    int N;
    cin >> N;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c <= r; ++c) {
            memset(mex, 0, sizeof(mex));
            for (int i = 0; i < r; ++i) {
                mex[a[i][c]] = 1;
            }
            for (int i = 0; i < c; ++i) {
                mex[a[r][i]] = 1;
            }
            for (int i = 0; i < 203; ++i) {
                if (mex[i] == 0) {
                    a[r][c] = i;
                    a[c][r] = i;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << a[i][j] << (j == N - 1 ? "\n" : " ");
        }
    }
}
