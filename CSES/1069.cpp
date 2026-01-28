#include "iostream"
using namespace std;

int main() {
    string S; cin >> S;
    int mx = 0;
    char cc = ' ';
    int curr = 0;
    for (auto &i : S) {
        if (i != cc) {
            mx = max(mx, curr);
            curr = 0;
            cc = i;
        }
        curr ++;
    }
    mx = max(mx, curr);
    cout << mx << "\n";
}
