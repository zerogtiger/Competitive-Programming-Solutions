#include "iostream"
#include "vector"
#include "set"
#include <algorithm>
using namespace std;

int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> E1(N/2);
    vector<int> E2(N/2);
    set<int> tmp;
    vector<int> B;
    for (auto &i : E1) {
        cin >> i;
        tmp.insert(i);
    }
    for (auto &i : E2) {
        cin >> i;
        tmp.insert(i);
    }
    for (int i =1 ; i <= 2*N; ++i) {
        if (!tmp.count(i))
            B.push_back(i);
    }
    sort(B.begin(), B.end());
    sort(E1.begin(), E1.end());
    sort(E2.begin(), E2.end());

    int curr = N/2;
    int ret =0;
    for (auto & i : E1) {
        for (; curr < N && B[curr] < i; ++curr) { }
        if (curr == N) 
            break;
        else {
            curr ++;
            ret ++;
        }
    }
    curr = 0;
    for (auto & i : E2) {
        if (i > B[curr]) {
            ret ++;
            curr ++;
        }
    }
    cout << ret << "\n";
    
}
