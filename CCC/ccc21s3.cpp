// Solution by zerogtiger on Github

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 2e5+5;
int N, p[MM], w[MM], d[MM]; vector<pi> vec; ll dy, ans;
ll f(int pos) {
    ll ret = 0;
    for(int i=1; i<=N; i++) {
        if(p[i] - d[i] > pos) ret += (ll)w[i]*(p[i] - d[i] - pos);
        else if(p[i] + d[i] < pos) ret += (ll)w[i]*(pos - p[i] - d[i]);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> p[i] >> w[i] >> d[i];  dy -= w[i];
        vec.push_back({p[i] - d[i], w[i]});  vec.push_back({p[i]+d[i], w[i]});
    }
    sort(vec.begin(), vec.end());
    for(pi cur : vec){
        int pos = cur.first, v = cur.second;
        dy += v;
        if(dy >= 0) { cout << f(pos) << "\n"; return 0; }
    }
}