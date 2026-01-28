#include "iostream"

using namespace std;
int main() {
    long long T;
    long long N;
    cin >> N;
    T = N * (N +1)/2;
    N--;
    while  (N--) {
        long long tmp; cin >> tmp;
        T -= tmp;
    }
    cout << T;
}
