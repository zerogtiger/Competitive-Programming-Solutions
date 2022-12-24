// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

int M, N, A[75 + 1], ans;

int main()
{
    cin >> M >> N;
    for (int i = 1; i <= M; i++)
    {
        int index;
        cin >> index;
        A[index]++;
    }

    for (int i = 75; i >= 1; i--)
    {
        if (ans + A[i] > N)
            break;
        ans += A[i];
    }
    cout << ans << endl;
}