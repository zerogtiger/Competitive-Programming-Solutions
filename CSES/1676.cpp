#include "iostream"
using namespace std;

const int MM = 1e5 + 4;
int dsu[MM];
int sz[MM];

int find(int curr)
{
    if (dsu[curr] == curr)
        return curr;
    return dsu[curr] = find(dsu[curr]);
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        dsu[i] = i;
        sz[i] = 1;
    }
    int mx = 1;
    int cnt = N;
    while (M--)
    {
        int a, b;
        cin >> a >> b;
        int A = find(a);
        int B = find(b);
        if (A != B)
        {
            cnt--;
            sz[A] += sz[B];
            dsu[B] = A;
        }
        mx = max(mx, sz[A]);
        cout << cnt << " " << mx << "\n";
    }
}
