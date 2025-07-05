#include "iostream"
#include <set>

using namespace std;

char a[3][3];
int main()
{
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }
    set<char> I;
    set<pair<char, char>> G;
    set<char> s;
    for (int i = 0; i < 3; ++i) {
        s.clear();
        for (int j = 0; j < 3; ++j) {
            s.insert(a[i][j]);
        }
        if (s.size() == 1) {
            I.insert(*s.begin());
        }
        if (s.size() == 2) {
            G.insert({*s.begin(), *(++s.begin())});
        }
    }
    for (int i = 0; i < 3; ++i) {
        s.clear();
        for (int j = 0; j < 3; ++j) {
            s.insert(a[j][i]);
        }
        if (s.size() == 1) {
            I.insert(*s.begin());
        }
        if (s.size() == 2) {
            G.insert({*s.begin(), *(++s.begin())});
        }
    }
    s.clear();
    for (int i = 0; i < 3; ++i) {
        s.insert(a[i][i]);
    }
    if (s.size() == 1) {
        I.insert(*s.begin());
    }
    if (s.size() == 2) {
        G.insert({*s.begin(), *(++s.begin())});
    }
    s.clear();
    for (int i = 0; i < 3; ++i) {
        s.insert(a[2 - i][i]);
    }
    if (s.size() == 1) {
        I.insert(*s.begin());
    }
    if (s.size() == 2) {
        G.insert({*s.begin(), *(++s.begin())});
    }
    cout << I.size() << "\n" << G.size() << "\n";
}
