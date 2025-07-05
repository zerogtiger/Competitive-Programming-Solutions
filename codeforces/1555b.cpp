#include "iostream"
#include <algorithm>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int W, H, w, h;
        cin >>W  >> H;
        pair<int, int> ll, tr;
        cin >> ll.first >> ll.second >> tr.first >> tr.second;
        cin >> w >> h;
        if (w + tr.first - ll.first > W && h + tr.second - ll.second > H) {
            cout << "-1\n";
            continue;
        }
        int ans = 0x3f3f3f3f;
        if (w + tr.first - ll.first <= W) {
            ans = max(0, min({ans, w - ll.first, w - (W - tr.first)}));
        }
        if (h + tr.second - ll.second <= H) {
            ans = max(0, min({ans, h - ll.second, h - (H - tr.second)}));
        }
        cout << (ans == 0x3f3f3f3f? -1 : ans) << "\n";
    }

}
