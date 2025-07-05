#include "iostream"
#define x first
#define y second
using namespace std;
int main()
{
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    pair<pair<int, int>, pair<int, int>> b1, b2, t;
    cin >> b1.first.x >> b1.first.y >> b1.second.x >> b1.second.y;
    cin >> b2.first.x >> b2.first.y >> b2.second.x >> b2.second.y;
    cin >> t.first.x >> t.first.y >> t.second.x >> t.second.y;

    pair<int, int> b1mn = {max(b1.first.x, t.first.x), max(b1.first.y, t.first.y)};
    pair<int, int> b1mx = {min(b1.second.x, t.second.x), min(b1.second.y, t.second.y)};
    int ans = -max(b1mx.first - b1mn.first, 0) * max(b1mx.second - b1mn.second, 0);

    b1mn = {max(b2.first.x, t.first.x), max(b2.first.y, t.first.y)};
    b1mx = {min(b2.second.x, t.second.x), min(b2.second.y, t.second.y)};
    ans -= max(b1mx.first - b1mn.first, 0) * max(b1mx.second - b1mn.second, 0);
    ans += (b1.second.x - b1.first.x) * (b1.second.y - b1.first.y);
    ans += (b2.second.x - b2.first.x) * (b2.second.y - b2.first.y);
    cout << ans << "\n";
}
