#include "iostream"
#include <algorithm>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

int main()
{
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    int N;
    cin >> N;
    map<string, int> mp;
    while (N--) {
        string tmp;
        int delta;
        cin >> tmp >> delta;
        mp[tmp] += delta;
    }
    if (mp.size() != 7) {
        mp[" "] = 0;
    }
    vector<pair<int, string>> v;
    for (auto& p : mp) {
        v.push_back({p.second, p.first});
    }
    sort(v.begin(), v.end());
    int val = v[0].first;
    bool flag = false;
    string out = "Tie";
    for (auto& p : v) {
        if (p.first == val && flag) {
            out = "Tie";
            break;
        }
        else if (p.first != val && !flag) {
            out = p.second;
            flag = true;
            val = p.first;
        }
    }
    cout << out << "\n";
}
