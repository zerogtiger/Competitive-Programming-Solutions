#include "iostream"
using namespace std;

struct rect {
    int x1, x2, y1, y2;
};
rect intersect(rect r1, rect r2)
{
    return rect{max(r1.x1, r2.x1), min(r1.x2, r2.x2), max(r1.y1, r2.y1), min(r1.y2, r2.y2)};
}
int main()
{
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    rect a, b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    auto ret = intersect(a, b);
    if (ret.x1 >= ret.x2 || ret.y1 >= ret.y2)
        cout << (a.x2 - a.x1) * (a.y2 - a.y1) << "\n";
    else if (ret.x2 - ret.x1 == a.x2 - a.x1) {
        if (ret.y2 < a.y2 && ret.y1 > a.y1) {
            cout << (a.y2 - a.y1) * (a.x2 - a.x1) << "\n";
        }
        else
            cout << (a.y2 - a.y1 - (ret.y2 - ret.y1)) * (a.x2 - a.x1) << "\n";
    }
    else if (ret.y2 - ret.y1 == a.y2 - a.y1) {
        if (ret.x2 < a.x2 && ret.x1 > a.x1) {
            cout << (a.y2 - a.y1) * (a.x2 - a.x1) << "\n";
        }
        else
        cout << (a.x2 - a.x1 - (ret.x2 - ret.x1)) * (a.y2 - a.y1) << "\n";
    }
    else
        cout << (a.x2 - a.x1) * (a.y2 - a.y1) << "\n";
}
