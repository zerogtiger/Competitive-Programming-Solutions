#include "iostream"
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, int> st;
    int ans =0;
    while (N--) {
        int i;
        cin >> i;
        auto res = st.upper_bound(i);
        if (res == st.end()) {
            st[i]++;
            ans++;
        }
        else {
            st[res->first] --;
            if (st[res->first] == 0)
                st.erase(res->first);
            st[i]++;
        }
    }
    cout << ans << "\n";
}
