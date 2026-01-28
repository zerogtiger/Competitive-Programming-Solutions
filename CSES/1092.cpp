#include "iostream"
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    if (N%4 == 2 || N%4 == 1) {
        cout << "NO\n";
    }
    else if (N%4 == 3) {
        vector<int> first, second;
        first.push_back(N);
        for (int i = 1; i <= (N - 1)/2; ++i) {
            if (i % 2 == 1) {
                second.push_back(i);
                second.push_back(N - i);
            }
            else {
                first.push_back(i);
                first.push_back(N - i);
            }
        }
        cout << "YES\n";
        cout << first.size() << "\n";
        for (auto &i : first)
            cout << i << " ";
        cout << "\n" << second.size() << "\n";
        for (auto &i : second)
            cout << i << " ";
    }
    else if (N%4 == 0) {
        vector<int> first, second;
        for (int i = 1; i <= N/2; ++i) {
            if (i % 2 == 1) {
                second.push_back(i);
                second.push_back(N + 1 - i);
            }
            else {
                first.push_back(i);
                first.push_back(N  + 1- i);
            }
        }
        cout << "YES\n";
        cout << first.size() << "\n";
        for (auto &i : first)
            cout << i << " ";
        cout << "\n" << second.size() << "\n";
        for (auto &i : second)
            cout << i << " ";
    }
}
