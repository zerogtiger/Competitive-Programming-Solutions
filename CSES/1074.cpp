#include "iostream"
#include <vector>
using namespace std;



vector<int> P;

long long cost(int length) {
    long long ret  = 0;
    for (auto  &i : P) {
        ret += abs(length - i);
    }
    return ret;
}

int main(){
    int N;
    cin >> N;
    while (N--) {
        int i;
        cin >> i;
        P.push_back(i);
    }
    int lft = 0, rht = 1e9;
    lft --;
    while (lft < rht) {
        int mid =lft +  (rht - lft + 1)/2;
        if (cost(mid - 1) < cost(mid)) {
            rht = mid - 1;
        }
        else {
            lft = mid;
        }
    }
    cout << cost(lft) << "\n";
}
