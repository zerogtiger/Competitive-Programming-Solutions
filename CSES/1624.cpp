#include "iostream"
#include <set>
using namespace std;

set<pair<int, int>> st;
int ans = 0;
void run(int row, int mask, int dm, int om)
{
    if (row == 8)
        ans++;
    else {
        for (int i = 0; i < 8; ++i) {
            if (!(mask & (1 << i))
                    && !st.count({row, i}) 
                    && !(dm & (1 << (row + i)))
                    && !(om & (1 << (row + 7 - i)))
                    ) {
                run(row + 1, mask | (1 << i), dm | (1 << (row + i)), om | (1 << (row + 7 - i)));
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 8; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; ++j) {
            if (s[j] == '*') {
                st.insert({i, j});
            }
        }
    }
    run(0, 0, 0, 0);
    cout << ans << "\n";
}
