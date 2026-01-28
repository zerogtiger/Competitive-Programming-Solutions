#include "iostream"
#include "cmath"
using namespace std;

typedef  long long ll ;

int main() {
    int N;
    cin >> N;
    for (ll i = 0; i < (ll) pow(2, N); ++i) {
        for (int j = N - 1; j >=0; --j)  {
            ll div = pow(2, j);
            switch ((i/div)%4) {
                case 0: 
                case 3: 
                    cout << 0;
                    break;
                case 1:
                case 2: 
                    cout << 1;
                    break;
            }
        }
        cout << "\n";
    }
}
