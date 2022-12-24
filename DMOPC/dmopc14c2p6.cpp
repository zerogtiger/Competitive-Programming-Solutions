// Solution by zerogtiger on Github

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<pi, pi> piii;
const int MM = 1e5+5;

int N, Q; ll ans[MM], bit[MM]; vector<pi> a; vector<piii> q; int atmp[MM];
void update(int pos, int val)
{
	for (; pos < MM; pos+=pos&-pos)
	{
		bit[pos]+=(ll)val;
	}
}
ll query(int pos)
{
	ll ret = 0;
	for (; pos>0; pos-=pos&-pos)
	{
		ret += bit[pos];
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	for (int m, i = 1; i <= N; i++)
	{
		cin >> m;
		a.push_back({m, i});
	}
	cin >> Q;
	for (int a, b, m, i = 1; i <= Q; i++)
	{
		cin >> a >> b >> m;
		q.push_back({{m, i}, {a, b}});
	}
	sort(q.begin(), q.end());
	sort(a.begin(), a.end());
	int currq = Q-1, curra = N-1;
	for (int i = 20000; i >= 0; i--)
	{
		while (a[curra].first>=i && curra>=0)
		{
			update(a[curra].second, a[curra].first);
			atmp[a[curra].second]=a[curra].first;
			curra--;
		}
		while (q[currq].first.first>=i && currq >= 0)
		{
			ans[q[currq].first.second] = query(q[currq].second.second+1)-query(q[currq].second.first);
			currq--;
		}
	}
	for (int i = 1; i <= Q; i++) 
	{
		cout << ans[i] << "\n";
	}
}

