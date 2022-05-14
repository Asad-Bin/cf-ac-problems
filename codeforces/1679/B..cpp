// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 2e5;
ll ara[MX+5], tree[4*MX+5], lazy[4*MX+5];
void build(int at, int l, int r)
{
	if(l == r){
		tree[at] = ara[l-1];
		return;
	}
	
	int mid = (l+r)/2;
	
	build(at*2, l, mid);
	build(at*2+1, mid+1, r);
	
	tree[at] = tree[at*2] + tree[at*2+1];
}
void update(int at, int l, int r, int L, int R, ll val)
{
		//cout << at << ' ' << l << ' ' << r << "\n";
	if(L <= l && r <= R){
		lazy[at] = val;
		
		tree[at] = val*(r-l+1);
		
		//cout << at << ' ' << l << ' ' << r << ' ' << tree[at] << "\n";
		
		return;
	}
	if(r < L || R < l) return;
	
	int mid = (l+r)/2;
	
	if(lazy[at]){
		lazy[at*2] = lazy[at];
		lazy[at*2+1] = lazy[at];
		
		tree[at*2] = lazy[at]*(mid-l+1);
		tree[at*2+1] = lazy[at]*(r-mid);
		
		lazy[at] = 0;
	}
	
	update(at*2, l, mid, L, R, val);
	update(at*2+1, mid+1, r, L, R, val);
	
	tree[at] = tree[at*2] + tree[at*2+1];
}
int main()
{
	int n, q, t, i, x;
	
	cin >> n >> q;
	
	for(int K = 0; K < n; K++) cin >>  ara[K];
	
	memset(tree, 0LL, sizeof tree);
	memset(lazy, 0LL, sizeof lazy);
	build(1, 1, n);
	
	while(q--){
		cin >> t;
		if(t == 1){
			cin >> i >> x;
			
			update(1, 1, n, i, i, x);
			
			cout << tree[1] << "\n";
		}
		else{
			cin >> x;
			
			update(1, 1, n, 1, n, x);
			cout << tree[1] << "\n";
		}
	}
	
	return 0;
}




















































