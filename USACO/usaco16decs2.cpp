#include "iostream"
#include <map>
using namespace std;
int main()
{
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    int N;
    cin >> N;
    map<pair<string, string>, int> st;
    int ans = 0;
    while (N--) {
        string C, S;
        cin >> C >> S;
        C = C.substr(0, 2);
        if (st[{S, C}] != 0 && C != S)
            ans+= st[{S, C}];
        st[{C, S}] ++;
    }
    cout << ans << "\n";
}
