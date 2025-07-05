#include "iostream"
#include <set>
using namespace std;

int main()
{

    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int N;
    cin >> N;
    string S;
    cin >> S;
    set<string> st;
    for (int l = 1; l <= N; ++l) {
        st.clear();
        for (int i = l; i <= N; ++i) {
            // cout << i << "\n";
            // cout << l << "\n";
            // cout << S.substr(i - l, l) << "\n";
            if (st.count(S.substr(i - l, l)) == 1) {
                goto end;
            }
            else {
                st.insert(S.substr(i - l, l));
            }
        }
        cout << l << "\n";
        return 0;
    end:
        continue;
    }
}
