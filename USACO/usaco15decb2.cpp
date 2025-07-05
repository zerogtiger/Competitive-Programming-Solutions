#include "iostream"
#include <vector>
#include <array>

using namespace std;

int main()
{
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int N, M;
    cin >> N >> M;
    vector<array<int, 3>> road(N), speed(M);
    int accum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> road[i][1] >> road[i][2];
        road[i][0] = accum;
        road[i][1] += accum;
        accum = road[i][1];
    }
    accum = 0;
    for (int i = 0; i < M; ++i) {
        cin >> speed[i][1] >> speed[i][2];
        speed[i][0] = accum;
        speed[i][1] += accum;
        accum = speed[i][1];
    }
    int I = 0, J = 0, mx = 0;
    while (I < N || J < M) {
        int i = min(I, N - 1);
        int j = min(J, M - 1);
        mx = max(mx, speed[j][2] - road[i][2]);
        if (road[i][1] == speed[j][1]) {
            I++;
            J++;
        }
        else if (road[i][1] > speed[j][1]) {
            ++J;
        }
        else {
            ++I;
        }
    }
    cout << mx << "\n";
}
