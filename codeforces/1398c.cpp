#include "iostream"
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> V(N + 2);
        map<int, int> mp;
        V[0] = 0;
        ll ans = 0;
        mp[0]++;
        for (int i = 1; i <= N; ++i ) {
            char c;
            cin >> c;
            V[i] = c - '0' + V[i - 1];
            ans += mp[V[i] - i];
            mp[V[i] - i]++;
        }
        cout << ans << "\n";
    }
}
