#include "iostream"
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, long long> mp;
    int prev = 0;
    mp[0] ++;
    long long ans = 0;
    for (int i = 0; i < N; ++i ) {
        int a;
        cin >> a;
        prev = ((prev + a)%N + N)%N;
        ans += mp[prev];
        mp[prev]++;
    }
    cout << ans << "\n";
}
