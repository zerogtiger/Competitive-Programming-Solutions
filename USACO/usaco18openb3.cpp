#include "iostream"
#include "map"
#include "set"
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

vector<int> ans;
map<string, vector<string>> asc;
map<string, vector<string>> des;
set<string> visited;

void dfs(string curr, string dest, vector<int>& path)
{
    visited.insert(curr);
    if (curr == dest) {
        ans = path;
        return;
    }
    path.push_back(-1);
    for (auto& p : asc[curr]) {
        if (!visited.count(p)) {
            dfs(p, dest, path);
        }
    }
    path.pop_back();
    path.push_back(1);
    for (auto& p : des[curr]) {
        if (!visited.count(p)) {
            dfs(p, dest, path);
        }
    }
    path.pop_back();
}

int main()
{
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);
    int N;
    cin >> N;
    string a, b;
    cin >> a >> b;
    while (N--) {
        string p, q;
        cin >> p >> q;
        asc[q].push_back(p);
        des[p].push_back(q);
    }
    vector<int> tmp;
    dfs(a, b, tmp);
    // for (auto &i : ans)
    //     cout << i << " ";
    // cout << "\n";
    if (ans.size() == 0) {
        cout << "NOT RELATED\n";
    }
    else if (ans.size() == 2 && ans[0] == -1 && ans[1] == 1) {
        cout << "SIBLINGS\n";
    }
    else if (find(ans.begin(), ans.end(), -1) == ans.end() ||
             find(ans.begin(), ans.end(), 1) == ans.end()) {
        int val = ans.size();
        if (find(ans.begin(), ans.end(), -1) == ans.end()) {
            swap(a, b);
        }
        cout << b << " is the ";
        for (int i = 0; i < val - 2; ++i) {
            cout << "great-";
        }
        if (val >= 2) {
            cout << "grand-";
        }
        cout << "mother of " << a;
    }
    else if (find(ans.begin(), ans.end(), 1) == ans.end() - 1) {
        int val = ans.size() - 1;
        cout << b << " is the ";
        for (int i = 0; i < val - 2; ++i) {
            cout << "great-";
        }
        cout << "aunt of " << a;
    }
    else if (find(ans.rbegin(), ans.rend(), -1) == ans.rend() - 1) {
        swap(a, b);
        int val = ans.size() - 1;
        cout << b << " is the ";
        for (int i = 0; i < val - 2; ++i) {
            cout << "great-";
        }
        cout << "aunt of " << a;
    }
    else {
        cout << "COUSINS";
    }
}
