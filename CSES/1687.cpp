#include "iostream"
#include "vector"
#include <cmath>
#include <cstring>
using namespace std;

int N, Q;
const int MM = 2e5 + 5;
vector<int> adj[MM];
int ancester[MM][20];

void fun(int curr, vector<int>& v)
{
    v.push_back(curr);
    for (int i = 1; i < v.size(); i *= 2)
    {
        ancester[curr][(int) log2(i)] = v[v.size() - i - 1];
    }
    for (auto& i : adj[curr])
    {
        fun(i, v);
    }
    v.pop_back();
}

int main()
{
    cin >> N >> Q;
    for (int i = 2; i <= N; ++i)
    {
        int K;
        cin >> K;
        adj[K].push_back(i);
    }
    memset(ancester, -1, sizeof(ancester));
    vector<int> V;
    fun(1, V);
    while (Q--)
    {
        int X, K;
        cin >> X >> K;
        while (K != 0)
        {
            int jp = (K & -K);
            if (ancester[X][(int) log2(jp)] < 0)
            {
                cout << -1 << "\n";
                goto end;
            }
            X = ancester[X][(int) log2(jp)];
            K -= (K & (-K));
        }
        cout << X << "\n";
    end:
        continue;
    }
}
