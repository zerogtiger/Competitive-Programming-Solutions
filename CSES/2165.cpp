#include "iostream"
#include "vector"
using namespace std;

vector<pair<int, int>> V;

inline int ex(int a, int b) {
    return 6 - a - b;
}

void fun(int N, int from, int to) {
    if (N == 1) {
        V.push_back({from, to});
    }
    else {
        fun(N - 1, from, ex(from, to));
        V.push_back({from, to});
        fun(N - 1, ex(from, to), to);
    }
}
int main() {
    int N;
    cin >> N;
    fun(N, 1, 3);
    cout << V.size() << "\n";
    for (auto &p : V)
        cout << p.first <<  " " << p.second << "\n";
}
