#include "iostream"
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (long long i = 1; i <= N; ++i) {
        switch (i) {
            case 1: 
                cout << 0 << "\n";
                break;
            case 2: 
                cout << 6 << "\n";
                break;
            case 3: 
                cout << 28 << "\n";
                break;
            case 4: 
                cout << 96 << "\n";
                break;
            case 5: 
                cout << 252 << "\n";
                break;
            default:
                cout << ((long long) pow(i - 4, 2) * (i * i - 9) + 4 * (i * i - 3) + 8*(i * i - 4) + (12 + (i -
                            6) * 4) * (i * i - 5) + (8 + (i - 6) * 4) * (i*i - 7))/2 << "\n";
                break;
        }
    }
}
