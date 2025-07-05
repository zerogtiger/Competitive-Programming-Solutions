#include "iostream"
#include <algorithm>
#include <set>

using namespace std;
int ans[28];
int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int N;
    cin >> N;
    while (N--) {
        string A, B;
        cin >> A >> B;
        multiset<char> mA, mB;
        for (auto &c : A) {
            mA.insert(c);
        }
        for (auto &c : B) {
            mB.insert(c);
        }
        // for (auto &c : mA) {
        //     cout << c << ", ";
        // }
        // for (auto &c : mB) {
        //     cout << c << ", ";
        // }
        // cout << "\n";
        for (char i = 'a'; i <= 'z'; ++i) {
            ans [i - 'a'] += max(mA.count(i), mB.count(i));
        }
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        cout << ans [i - 'a'] << "\n";
    }
}
