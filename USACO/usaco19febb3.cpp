#include "iostream"
#include "vector"

using namespace std;

int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<string, pair<int, int>>> V(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i].first >> V[i].second.first >> V[i].second.second;
    }
    pair<int, int> F = {-0x3f3f3f3f, 0x3f3f3f3f}, L{-0x3f3f3f3f, 0x3f3f3f3f};
    bool init = true;
    for (int i = 0; i < N; ++i) {
        if (V[i].first == "on" && !init) {
            F.first += V[i].second.first;
            F.second += V[i].second.second;
        }
        else if (V[i].first == "off"&& !init) {
            F.first -= V[i].second.second;
            F.second -= V[i].second.first;
        }
        else if (V[i].first == "none") {
            init = false;
            F.first = max(F.first, V[i].second.first);
            F.second = min(F.second, V[i].second.second);
        }
    }
    init = true;
    for (int i = N - 1; i >=0; --i) {
        if (V[i].first == "off" && !init) {
            L.first += V[i].second.first;
            L.second += V[i].second.second;
        }
        else if (V[i].first == "on" && !init) {
            L.first -= V[i].second.second;
            L.second -= V[i].second.first;
        }
        else if (V[i].first == "none") {
            init = false;
            L.first = max(L.first, V[i].second.first);
            L.second = min(L.second, V[i].second.second);
        }
    }
    cout << max(L.first, 0) << " " << L.second << "\n";
    cout << max(0, F.first) << " " << F.second << "\n";
}
