#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> V(N);
    for (auto& s : V)
        cin >> s;
    sort(V.begin(), V.end(), [](const string& x, const string& y) {
            return (x + y) < (y + x);
    });
    for (auto& s : V) {
        cout << s;
    }
    cout << "\n";
}
