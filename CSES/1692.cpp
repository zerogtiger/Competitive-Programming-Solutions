#include "iostream"
#include "set"
#include "vector"
using namespace std;

const int MM = (1 << 15) + 4;

set<int> adj[MM];
int main()
{
    int N;
    cin >> N;
    if (N == 1)
    {
        cout << "10";
        return 0;
    }
    int AA = (1 << (N - 1)) - 1;
    for (int i = 0; i < (1 << (N - 1)); ++i)
    {
        adj[i].insert((i << 1) & AA);
        adj[i].insert(((i << 1) & AA) | 1);
    }
    string ans;
    vector<int> st;
    st.push_back(0);
    while (!st.empty())
    {
        int curr = st.back();
        if (adj[curr].empty())
        {
            ans.push_back((curr & 1) + '0');
            st.pop_back();
        }
        else
        {
            int nxt = *(adj[curr].begin());
            adj[curr].erase(nxt);
            st.push_back(nxt);
        }
    }
    for (int i = 0; i < N - 2; ++i)
    {
        ans.push_back('0');
    }
    cout << ans << "\n";
}
