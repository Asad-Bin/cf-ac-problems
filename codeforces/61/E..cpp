/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 1e6;
ll ara[MX+5], tree[4*MX+5], num[MX+5];

void update(int at, int l, int r, int idx, ll val)
{
	if(l == r){
		tree[at] += val;
		return;
	}
	
	int mid = (l+r)/2;
	
	if(idx <= mid) update(at*2, l, mid, idx, val);
	else update(at*2+1, mid+1, r, idx, val);
	
	tree[at] = tree[at*2] + tree[at*2+1];
}
ll query(int at, int l, int r, int L, int R)
{
	if(L > R) return 0;
	if(R < l || r < L) return 0;
	if(L <= l && r <= R) return tree[at];
	
	int mid = (l+r)/2;
	
	ll ans = 0;
	ans += query(at*2, l, mid, L, R);
	ans += query(at*2+1, mid+1, r, L, R);
	
	return ans;
}
int main()
{
	int n;
	
	cin >> n;
	
	map<int, int> mp;
	for(int K = 0; K < n; K++){
		cin >> ara[K];
		mp[ara[K]] = 1;
	}
	
	int i = 0;
	for(auto x:mp) mp[x.first] = ++i;
	for(int K = 0; K < n; K++) ara[K] = mp[ara[K]];
	//for(int K = 0; K < n; K++) cout << ara[K] << ' ';
	//cout << "\n";
	
	for(int K = n-1; K >= 0; K--){
		num[K] = query(1, 1, i, 1, ara[K]-1);
		update(1, 1, n, ara[K], 1);
	}
	//for(int K = 0; K < n; K++) cout << num[K] << ' ';
	//cout << "\n";
	
	
	ll ans = 0;
	memset(tree, 0LL, sizeof tree);
	for(int K = n-1; K >= 0; K--){
		ans += query(1, 1, n, 1, ara[K]-1);
		update(1, 1, n, ara[K], num[K]);
	}
	
	cout << ans << "\n";
	
	
	return 0;
}
