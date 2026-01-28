#include "iostream"
#include "vector"
using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    vector<int> V(N);
    for (auto& i : V) {
        cin >> i;
    }
    int lft = 0, rht = 0, curr = 0;
    int ans = 0;
    for (; rht < N || lft < rht;) {
        if (curr == X) {
            ++ans;
            curr -= V[lft++];
        }
        else if (curr < X) {
            if (rht == N)
                break;
            curr += V[rht++];
        }
        else {
            curr -= V[lft++];
        }
    }
    cout << ans << "\n";
}
