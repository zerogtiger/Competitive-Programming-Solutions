#include "iostream"
#include "set"
using namespace std;

int N;
string s;
int ans = 0;
set<string> st;
void run(int mask, string accum)
{
    {
        if (mask == (1 << N) - 1)
            st.insert(accum);
        else {
            for (int i = 0; i < N; ++i) {
                if (!(mask & (1 << i))) {
                    run(mask | (1 << i), accum + s[i]);
                }
            }
        }
    }
}

int main()
{
    cin >> s;
    N = s.length();
    run(0, "");
    cout << st.size() << "\n";
    for (auto &ss : st)
        cout << ss << "\n";
}
