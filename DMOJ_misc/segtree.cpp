// Solution by zerogtiger on Github

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
struct node {int l, r, val;} seg[4*MM];
int N, M, a[MM]; char op;
void build(int l, int r, int idx)
{
	seg[idx].l = l; seg[idx].r = r;
	if(l == r) {seg[idx].val = a[l]; return;}
	int mid = (l+r)/2;
	build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
	seg[idx].val = min(seg[2*idx].val, seg[2*idx+1].val);
}

void update(int pos, int val, int idx)
{
	if (seg[idx].l == seg[idx].r)
	{
		seg[idx].val = val; return;
	}
	int mid = (seg[idx].l + seg[idx].r)/2;
	if (pos <= mid) update(pos, val, 2*idx);
	else update(pos, val, 2*idx+1);
	seg[idx].val = min(seg[2*idx].val, seg[2*idx+1].val);
	return;

}
int query(int l, int r, int idx)
{
	if (seg[idx].l == l && seg[idx].r == r)
	{
		return seg[idx].val;
	}
	int mid = (seg[idx].l + seg[idx].r)/2;
	if (r <= mid) return query(l, r, idx*2);
	if (l > mid) return query(l, r, idx*2+1);
	return min(query(l, mid, idx*2), query(mid+1, r, idx*2+1));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i<N; i++) cin >> a[i];
	build(0, N-1, 1);
	for (int x, y, i = 1; i <= M; i++)
	{
		cin >> op >> x >> y;
		if (op == 'M') update(x, y, 1);
		else cout << query(x, y, 1) << "\n";
	}
}


