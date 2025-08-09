#include "iostream"
#include "vector"
#include <map>
using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    vector<int> V(N + 1);
    map<int, int> mp;
    for (int i = 1; i <= N; ++i) {
        cin >> V[i];
        if (mp.count(X - V[i])) {
            cout << mp[X - V[i]] << " " << i << "\n";
            return 0;
        }
        mp[V[i]] = i;
    }
    cout << "IMPOSSIBLE\n";
}
