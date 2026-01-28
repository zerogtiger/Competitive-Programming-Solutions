#include "iostream"
#include <deque>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N == 1) {
        cout << "1\n";
    }
    else if (N <= 3) {
        cout << "NO SOLUTION\n";
    }
    else {
        deque<int> dq;
        dq.push_back(3);
        dq.push_back(1);
        dq.push_back(4);
        dq.push_back(2);
        int curr = 4;
        while (curr != N)  {
            curr ++;
            if (curr%2 == 1) {
                dq.push_back(curr);
            }
            else {
                dq.push_front(curr);
            }
        }
        for (auto &i : dq) {
            cout << i << " ";
        }
    }
}
