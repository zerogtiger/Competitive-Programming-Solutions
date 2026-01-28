#include "iostream"
#include "vector"
#include <algorithm>
#include <deque>
using namespace std;

const int MM = 1e5 + 4;
vector<int> adj[MM], jda[MM];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        jda[b].push_back(a);
    }
    adj[N].push_back(1);
    jda[1].push_back(N);
    for (int i = 1; i <= N; ++i)
    {
        if (adj[i].size() != jda[i].size())
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    vector<int> st;
    st.push_back(1);
    deque<int> ans;
    while (!st.empty())
    {
        int curr = st.back();
        if (adj[curr].empty())
        {
            ans.push_back(curr);
            st.pop_back();
        }
        else
        {
            int nxt = adj[curr].back();
            adj[curr].pop_back();
            st.push_back(nxt);
        }
    }
    ans.pop_back();
    while (!(ans.back() == 1 && ans.front() == N))
    {
        int bk = ans.back();
        ans.pop_back();
        ans.push_front(bk);
    }
    if (ans.size() != M + 1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    while (!ans.empty())
    {
        cout << ans.back() << " ";
        ans.pop_back();
    }
}
