#include "iostream"
using namespace std;

int main() {
    long long N;
    cin >> N;
    while (N !=1 ) {
        cout << N << " ";
        if (N % 2 == 1) {
            N = N * 3 + 1;
        }
        else {
            N /= 2;
        }
    }
    cout << 1 << "\n";
}
