#include "iostream"
#include <stack>
using namespace std;

int main()
{
    int N;
    cin >> N;
    stack<pair<int, int>> q;
    q.push({0, 0});
    for (int j = 1; j <= N; ++j) {
        int i;
        cin >> i;
        while (q.top().first >= i) {
            q.pop();
        }
        cout << q.top().second << " ";
        q.push({i, j});
    }
}
