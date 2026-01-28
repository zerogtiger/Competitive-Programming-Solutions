#include "iostream"
#include "map"
#include "vector"
using namespace std;

int main()
{
    string S;
    cin >> S;
    map<int, int> mp;
    for (auto& i : S) {
        mp[i - 'A']++;
    }
    if (S.length() % 2 == 1) {
        int flag = -1;
        vector<int> V;
        for (auto& p : mp) {
            if (p.second % 2 == 1 && flag != -1) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            else if (p.second % 2 == 1) {
                flag = p.first;
            }
            for (int i = 0; i < p.second / 2; ++i) {
                V.push_back(p.first);
            }
        }
        if (flag == -1) {
            cout << "NO SOLUTION\n";
            return 0;
        }
        for (auto &i : V) {
            cout << string(1, (i + 'A'));
        }
        cout << string(1, (flag + 'A'));
        for (int i = V.size() - 1;  i >= 0; --i) {
            cout << string(1, (V[i] + 'A'));
        }
    }
    else {
        vector<int> V;
        for (auto& p : mp) {
            if (p.second % 2 == 1) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            for (int i = 0; i < p.second / 2; ++i) {
                V.push_back(p.first);
            }
        }
        for (auto &i : V) {
            cout << string(1, (i + 'A'));
        }
        for (int i = V.size() - 1;  i >= 0; --i) {
            cout << string(1, (V[i] + 'A'));
        }
    }
}
