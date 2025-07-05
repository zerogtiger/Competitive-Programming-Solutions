#include "iostream"
#include "map"
#include "set"
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);
    int N;
    cin >> N;
    map<string, set<int>> mp;
    while (N--) {
        int K;
        cin >> K;
        string S;
        while (K--) {
            cin >> S;
            mp[S].insert(N);
        }
    }
    for (auto& p : mp) {
        for (auto& pp : mp) {
            if (p.first == pp.first) {
                continue;
            }
            set<int> inte;
            set_intersection(pp.second.begin(), pp.second.end(), p.second.begin(), p.second.end(),
                             inserter(inte, inte.begin()));
            if (!inte.empty() && pp.second.size() - inte.size() != 0 && p.second.size() - inte.size() != 0) {
                cout << "no\n";
                return 0;
            }
        }
    }
    cout << "yes" << "\n";
}
