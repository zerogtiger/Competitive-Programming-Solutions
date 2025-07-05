#include "iostream"
#include <vector>
using namespace std;

int main()
{
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for (auto& i : A) {
        char tmp;
        cin >> tmp;
        if (tmp == 'G')
            i = 1;
        else
            i = 0;
    }
    for (auto& i : B) {
        char tmp;
        cin >> tmp;
        if (tmp == 'G')
            i = 1;
        else
            i = 0;
    }
    bool flip = false;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] != B[i] && !flip) {
            flip = true;
        }
        else if (A[i] == B[i] && flip) {
            ans += 1;
            flip = false;
        }
    }
    ans += flip;
    cout << ans << "\n";
}
