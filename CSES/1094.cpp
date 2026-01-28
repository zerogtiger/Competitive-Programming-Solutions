#include "iostream"
using namespace std;

int main() {
    int N;
    cin >> N;
    long long last;
    cin >> last;
    N--;
    long long ans = 0;
    while (N--) {
        long long curr = 0;
        cin >> curr;
        ans += max((long long) 0, last - curr);
        last = max(curr, last);
    }
    cout << ans << "\n";
}
