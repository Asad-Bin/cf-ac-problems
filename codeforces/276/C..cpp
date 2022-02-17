/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;



const int MX = 2e5;
int tree[4*MX+5];
void propogate(int at){
	tree[at*2] += tree[at];
	tree[at*2+1] += tree[at];
	
	tree[at] = 0;
}
void update(int at, int l, int r, int L, int R)
{
	if(r < L || R < l) return;
	if(L <= l && r <= R){
		tree[at]++;
		
		return;
	}
	
	int mid = (l+r)/2;
	
	propogate(at);
	
	update(at*2, l, mid, L, R);
	update(at*2+1, mid+1, r, L, R);
}
int query(int at, int l, int r, int idx)
{
	if(l == r){
		return tree[at];
	}
	
	int mid = (l+r)/2;
	
	if(idx <= mid) return tree[at]+query(at*2, l, mid, idx);
	else return tree[at]+query(at*2+1, mid+1, r, idx);
}
int main()
{
	int n, q, l, r;
	
	cin>> n >> q;
	
	int ara[n+5], cnt[n+5];
	for(int K = 1; K <= n; K++) cin >> ara[K];
	
	sort(ara+1, ara+n+1);
	
	while(q--){
		cin >> l >> r;
		
		update(1, 1, n, l, r);
	}
	
	for(int K = 1; K <= n; K++){
		cnt[K] = query(1, 1, n, K);
	}
	sort(cnt+1, cnt+n+1);
	
	long long ans = 0;
	for(int K = n; K >= 1; K--) ans += (long long)ara[K]*cnt[K];
	
	cout << ans << "\n";
	
	return 0;
}
