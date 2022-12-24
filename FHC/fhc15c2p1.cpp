// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MM = 1e5+5;

int t, n; deque<int> o1, o2, e1, e2;
int main()
{
    ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);

    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) 
        {
            int temp;
            cin >> temp;
            o1.push_back(temp);
            o2.push_back(temp);
        }
        bool fail1 = 1;
        for (int i = 1; i <= n; i++) 
        {
            if (e1.empty()) {e1.push_back(o1.front()); o1.pop_front();}
            else if (e1.front() == o1.front()+1) {e1.push_front(o1.front()); o1.pop_front();}
            else if (e1.front() == o1.back()+1) {e1.push_front(o1.back()); o1.pop_back();}
            else if (e1.back() == o1.front()-1) {e1.push_back(o1.front()); o1.pop_front();}
            else if (e1.back() == o1.back()-1) {e1.push_back(o1.back()); o1.pop_back();}
            else {fail1 = false; break;}
        }

        bool fail2 = 1;
        for (int i = 1; i <= n; i++) 
        {
            if (e2.empty()) {e2.push_back(o2.back()); o2.pop_back();}
            else if (e2.front() == o2.front()+1) {e2.push_front(o2.front()); o2.pop_front();}
            else if (e2.front() == o2.back()+1) {e2.push_front(o2.back()); o2.pop_back();}
            else if (e2.back() == o2.front()-1) {e2.push_back(o2.front()); o2.pop_front();}
            else if (e2.back() == o2.back()-1) {e2.push_back(o2.back()); o2.pop_back();}
            else {fail2 = false; break;}
        }
        

        if (fail1 || fail2) cout << "Case #" << T << ": yes" << endl;
        else cout << "Case #" << T << ": no" << endl;
        e1.clear();
        e2.clear();
        o1.clear();
        o2.clear();
    }
}