// Solution by zerogtiger on Github

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 150005;

ll ans; int curr, N, psa[MM]; ll bit[2*MM];
void update(int pos)
{
	pos+=MM;
	for (; pos < 2*MM; pos+=pos&-pos)
	{
		bit[pos]++;
	}
}
ll query(int pos)
{
	ll ret = 0;
	pos+=MM;
	for (; pos > 0; pos-=pos&-pos)
	{
		ret += bit[pos];
	}
	return ret;
}
int main() 
{
	cin >> N;
	update(0);
	for (int v, i = 1; i <= N; i++)
	{
		cin >> v;
		psa[i] += psa[i-1]+(v==2? -1 : 1);
		curr+=(v==2? -1 : 1);
		ans += query(curr-1);
		update(curr);
	}
	cout << ans << "\n";
}
