#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> V(N);
    for (auto & p : V)
        cin >> p.second >> p.first;
    sort(V.begin(), V.end());
    int curr = 0; 
    int ans = 0;
    for (auto &p : V) {
        if (p.second >= curr) {
            ans ++;
           curr = p.first;
        }
    }
    cout << ans << "\n";


}
