#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;

int main()
{
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    vector<int> AA(N);
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        A[i] = {tmp, i};
        AA[i] = tmp;
    }
    sort(A.begin(), A.end());

    // for (auto& pp : A) {
    //     cout << pp.first << " | " << pp.second << "\n";
    // }
    // cout << "\n";

    int diff = -1;
    if (AA[0] > AA[1]) {
        diff = 0;
    }
    else if (AA[N - 2] > AA[N - 1]) {
        diff = N - 1;
    }
    else {
        for (int i = 1; i < N - 1; ++i) {
            if ((AA[i] < AA[i + 1] && AA[i - 1] > AA[i] && AA[i - 1] <= AA[i + 1]) ||
                (AA[i] > AA[i + 1] && AA[i - 1] < AA[i] && AA[i - 1] <= AA[i + 1])) {
                diff = i;
                break;
            }
        }
    }
    if (diff == -1) {
        cout << "0\n";
        return 0;
    }
    int target;
    for (int i = 0; i < N; ++i) {
        // cout << A[i].first << ", " << A[i].second << ", " <<  diff << "\n";
        if (A[i].second == diff) {
            target = i;
            break;
        }
    }

    // cout << diff << " | " << target << "\n";

    int delta = (target > diff ? 1 : -1);
    int last = -1;
    int ans = 0;
    for (int i = diff; i != target; i += delta) {
        if (AA[i + delta] != last) {
            ++ans;
            last = AA[i + delta];
        }
    }
    cout << ans << "\n";
}
