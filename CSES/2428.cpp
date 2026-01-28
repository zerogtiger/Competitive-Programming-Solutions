#include "iostream"
#include <map>
#include <vector>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> V(N);
    map<int, int> cnt;
    long long ans = 0;
    for (auto& i : V)
        cin >> i;
    int lft = 0, rht = 0;
    for (; rht <= N;) {
        while (cnt.size() > K) {
            cnt[V[lft]]--;
            if (cnt[V[lft]] == 0)
                cnt.erase(V[lft]);
            lft++;
        }
        ans += (long long) (rht - lft);
        // cout << lft << " " << rht << "\n";
        if (rht == N) {
            break;
        }
        cnt[V[rht++]]++;
    }
    cout << ans << "\n";
}
