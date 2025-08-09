#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int A[2503][2503];
int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> V(N);
    for (auto& p : V)
        cin >> p.first >> p.second;
    sort(V.begin(), V.end());
    int cnt = 1;
    for (auto& p : V)
        p.first = cnt++;
    sort(V.begin(), V.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; });
    cnt = 1;
    for (auto& p : V) {
        p.second = cnt++;
        A[p.first][p.second]++;
    }
    sort(V.begin(), V.end());
    for (int i = 1; i <= N + 1; ++i) {
        for (int j = 1; j <= N + 1; ++j) {
            A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int maxy = max(V[i].second, V[j].second);
            int miny = min(V[i].second, V[j].second);
            int top = A[V[j].first - 1][miny - 1] - A[V[j].first - 1][0] -  A[V[i].first][miny - 1] + A[V[i].first][0];
            int bot = A[V[j].first - 1][N] - A[V[j].first - 1][maxy] -  A[V[i].first][N] + A[V[i].first][maxy];
            ans += (long long) (top + 1)*(bot + 1);
        }
    }
    cout << ans + N + 1 << "\n";
}
