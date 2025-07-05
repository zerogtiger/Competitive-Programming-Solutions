#include "iostream"
using namespace std;


int N;
int a[22];

long long run(int i, long long lft, long long rht) {
    if (i == N) {
        return abs(lft - rht);
    }
    return min(run(i + 1, lft + a[i], rht), run(i + 1, lft, rht + a[i]));
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    cout << run(0, 0, 0) << "\n";
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    long long ans = 2e18;
    for (int m = 0; m < (1<<N); ++m) {
        long long lft = 0, rht = 0;
        for (int i = 0; i < N; ++i) {
            if (m & (1 << i))
                lft += a[i];
            else
                rht += a[i];
        }
        ans = min(ans, abs(lft - rht));
    }
    cout << ans << "\n";
}
