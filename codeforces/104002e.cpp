#include "iostream"
#include "vector"
#include <queue>
#include <set>
using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;
    priority_queue<ll> pq;
    for (int i = 0; i < N; ++i) {
        ll A; 
        cin >> A;
        pq.push(-A);
        if (i % 2 == 1)
            pq.pop();
    }
    ll ret = 0;
    while (!pq.empty()){
        ret += pq.top();
        pq.pop();
    }
    cout << -ret << "\n";



}
