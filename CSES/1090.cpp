#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int main() {
    int N, X;
    cin >> N>> X;
    vector<int> V(N);
    for (auto &i : V)
        cin >> i;
    sort(V.begin(), V.end());
    int ret = 0;
    int lft = 0, rht = N - 1;
    while (lft < rht) {
        ret ++;
        if (V[lft] + V[rht] > X) {
            rht--;
        }
        else {
            lft ++;
            rht --;
        }
    }
    cout << ret + (lft == rht ? 1 : 0) << "\n";
    
    


}
