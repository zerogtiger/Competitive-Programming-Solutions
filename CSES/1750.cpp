#include "iostream"
#include <cmath>
#include <cstring>
using namespace std;

const int MM = 2e5 + 5;
int ancester[MM][32];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    memset(ancester, -1, sizeof(ancester));
    for (int i = 1; i <= N; ++i)
    {
        int a;
        cin >> a;
        ancester[i][0] = a;
    }
    for (int pw = 1; pw <= 30; ++pw)
    {
        for (int i = 1; i <= N; ++i)
        {
            if (ancester[i][pw - 1] == -1)
            {
                continue;
            }
            ancester[i][pw] = ancester[ancester[i][pw - 1]][pw - 1];
        }
    }
    while (Q--)
    {
        int X, K;
        cin >> X >> K;
        for (; K > 0; K -= (K & -K))
        {
            int lvl = (int) log2(K & -K);
            X = ancester[X][lvl];
        }
        cout << X << "\n";
    }
}
