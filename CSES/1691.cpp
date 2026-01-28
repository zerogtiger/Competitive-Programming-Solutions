#include "iostream"
#include "set"
#include <stack>
#include <vector>
using namespace std;

const int MM = 1e5 + 5;
set<int> adj[MM];
int main() {
    int N, M;
    cin >> N >> M;
    for (int i =0 ; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for (auto &s : adj) {
        if (s.size() %2 != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    stack<int> st;
    vector<int> ans;
    st.push(1);
    while (!st.empty()) {
        int curr = st.top();
        if (adj[curr].size() == 0) {
            st.pop();
            ans.push_back(curr);
        }
        else {
            int b = *(adj[curr].begin());
            adj[curr].erase(b);
            adj[b].erase(curr);
            // ans.push_back(b);
            st.push(b);
        }
    }
    if (ans.size() != M + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (auto &i : ans) {
        cout  << i << " ";
    }
}
