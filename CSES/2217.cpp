#include "iostream"
#include "vector"
#include <set>
using namespace std;
typedef long long ll;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> prev(N + 2);
    vector<int> curr(N + 2);
    vector<int> V(N + 2);
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        V[i] = a;
        curr[a] = i;
        prev[a + 1] = i;
    }
    prev[1] = -1;
    ll ans = 0;

    for (int i = 1; i <= N; ++i) {
        ans += (prev[i] > curr[i]);
    }
    ans++;
    while (M--) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        int aa = V[A], bb = V[B];
        set<int> st = {aa, bb, aa + 1, bb + 1};
        ll d1 = 0;
        for (auto& i : st) {
            d1 += (i <= N ? prev[i] > curr[i] : 0);
        }
        swap(curr[aa], curr[bb]);
        swap(V[A], V[B]);

        prev[aa + 1] = curr[aa];
        prev[bb + 1] = curr[bb];

        ll d2 = 0;
        for (auto& i : st) {
            d2 += (i <= N ? prev[i] > curr[i] : 0);
        }
        ans += (d2 - d1);
        cout << ans << "\n";
    }
}
