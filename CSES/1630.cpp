#include "iostream"
#include "vector"
#include "algorithm"


typedef long long ll;

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<ll, ll>> V(N);
    for (auto  &p : V) {
        cin >> p.first >> p.second;
    }
    sort(V.begin(), V.end());
    ll curr =0 ;
    ll ret =0 ;
    for (auto &p : V) {
        curr += p.first;
        ret += p.second - curr;
    }
    cout << ret <<"\n";
}
