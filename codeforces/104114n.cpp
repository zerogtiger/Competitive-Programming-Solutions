#include "iostream"
#include "vector"
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> V(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        V[i + 1] = max(V[i + 1], V[i] - M);
    }
    for (int i = N - 1; i > 0; --i) {
        V[i - 1] = max(V[i - 1], V[i] - M);
    }
    for (int i = 0; i < N; ++i)
        cout << V[i] << (i == N - 1 ? "\n" : " ");
}
