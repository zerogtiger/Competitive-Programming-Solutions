#include "iostream"
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
using namespace std;

#define x first
#define y second

int main()
{
    vector<pair<pair<int, int>, char>> VV(3);
    cin >> VV[0].x.x >> VV[0].x.y >> VV[1].x.x >> VV[1].x.y >> VV[2].x.x >> VV[2].x.y;
    int total_area = VV[0].x.x * VV[0].x.y + VV[1].x.x * VV[1].x.y + VV[2].x.x * VV[2].x.y;
    VV[0].second = 'A';
    VV[1].second = 'B';
    VV[2].second = 'C';
    if (pow((int) sqrt(total_area), 2) != total_area) {
        cout << -1 << "\n";
        return 0;
    }
    int side_length = (int) sqrt(total_area);
    // cout << side_length << "in\n";
    sort(VV.begin(), VV.end());
    for (int I = 0; I < (1 << 3); ++I) {
        auto V = VV;
        for (int j = 0; j < 3; ++j) {
            if (I & (1 << j)) {
                swap(V[j].x.x, V[j].x.y);
            }
        }
        do {
            int rx = side_length - V[0].x.x;
            int ry = side_length - V[0].x.y;
            if (rx != 0 && ry != 0) {
                continue;
            }
            if (rx == 0 && ry > 0) {
                rx = side_length - V[1].x.x;
                ry -= V[1].x.y;
                if (rx != 0 && ry != 0) {
                    continue;
                }
                if (rx == 0 && ry > 0 && V[2].x.x == side_length && V[2].x.y == ry) {
                    cout << side_length << "\n";
                    for (int i = 0; i < side_length; ++i) {
                        for (int j = 0; j < side_length; ++j) {
                            if (i < V[0].x.y) {
                                cout << V[0].second;
                            }
                            else if (i < side_length - V[2].x.y) {
                                cout << V[1].second;
                            }
                            else {
                                cout << V[2].second;
                            }
                        }
                        cout << "\n";
                    }
                    return 0;
                }
                // 9 23 14 8 15 14
                else if (ry == 0 && rx > 0 && V[2].x.x == rx && V[2].x.y == V[1].x.y) {
                    cout << side_length << "\n";
                    for (int i = 0; i < side_length; ++i) {
                        for (int j = 0; j < side_length; ++j) {
                            if (i < V[0].x.y) {
                                cout << V[0].second;
                            }
                            else if (j < V[1].x.x) {
                                cout << V[1].second;
                            }
                            else {
                                cout << V[2].second;
                            }
                        }
                        cout << "\n";
                    }
                    return 0;
                }
            }
        } while (next_permutation(V.begin(), V.end()));
    }
    cout << -1 << "\n";
}
