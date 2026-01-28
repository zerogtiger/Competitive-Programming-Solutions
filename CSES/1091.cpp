#include "iostream"
#include "map"
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    map<int, int> H;
    while (N--) {
        int i;
        cin >> i;
        H[-i]++;
    }
    while (M--) {
        int T;
        cin >> T;
        auto val = H.lower_bound(-T);
        if (val == H.end()) {
            cout << "-1\n";
        }
        else {
            cout << -val->first << "\n";
            if (val->second == 1) {
                H.erase(val);
            }
            else 
                H[val->first]--;
        }
    }
}
