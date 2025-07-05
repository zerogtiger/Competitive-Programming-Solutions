#include "iostream"
using namespace std;

struct rect {
  long long x1, y1, x2, y2;
  long long area() { return max((long long) 0, (x2 - x1)) * max((long long) 0, (y2 - y1)); }
};

rect intersect(rect r1, rect r2) {
  return rect{max(r1.x1, r2.x1), max(r1.y1, r2.y1), min(r1.x2, r2.x2),
              min(r1.y2, r2.y2)};
}

int main() {
  rect w, b1, b2;
  cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
  cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
  cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;

  auto i1 = intersect(w, b1);
  if (i1.area() == w.area()) {
    cout << "NO\n";
    return 0;
  }
  if (i1.area() != 0) {
    if (i1.x2 - i1.x1 == w.x2 - w.x1 && (w.y2 == i1.y2 || w.y1 == i1.y1)) {
      // cout << "huh\n";
      if (w.y1 == i1.y1) {
        w.y1 = i1.y2;
      } else {
        w.y2 = i1.y1;
      }
    } else if (i1.y2 - i1.y1 == w.y2 - w.y1 &&
               (w.x2 == i1.x2 || w.x1 == i1.x1)) {
      // cout << "hhuh\n";
      if (w.x1 == i1.x1) {
        w.x1 = i1.x2;
      } else {
        w.x2 = i1.x1;
      }
    }
  }
  auto i2 = intersect(w, b2);
  if (i2.area() == w.area()) {
    cout << "NO\n";
  } else
    cout << "YES\n";
}
