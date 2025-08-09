#include "iostream"
#include "vector"
#include <set>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, Q;
        cin >> N >> Q;
        vector<int> V(N);
        for (auto &i : V)
            cin >> i;
        string S;
        cin >> S;
        vector<int> delta(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            delta[min(i, V[i - 1])] ++;
            delta[max(i, V[i - 1])]--;
        }
        for (int i = 1; i <= N; ++i)
            delta[i] += delta[i - 1];
        set<int> gaps;
        for (int i = 1; i < N; ++i) {
            if (S[i] == 'R' && S[i - 1] == 'L' && delta[i] != 0)
                gaps.insert(i);
        }
        while (Q--) {
            int I;
            cin >> I;
            S[I - 1] = (S[I - 1] == 'L' ? 'R' : 'L');
            if (S[I - 2] == 'L' && S[I - 1] == 'R' && delta[I - 1] != 0) {
                gaps.insert(I - 1);
            }
            else {
                gaps.erase(I - 1);
            }
            if (S[I - 1] == 'L' && S[I] == 'R' && delta[I] != 0) {
                gaps.insert(I);
            }
            else {
                gaps.erase(I);
            }
            if (gaps.size() == 0) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
}
