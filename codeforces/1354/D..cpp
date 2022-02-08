/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;

const int MX = 1e6;
int tree[4*MX+5];
void update(int at, int l, int r, int idx, int val){
	if(l == r){
		tree[at] += val;
		return;
	}
	
	int mid = (l+r)/2;
	
	if(idx <= mid) update(at*2, l, mid, idx, val);
	else update(at*2+1, mid+1, r, idx, val);
	
	tree[at] = tree[at*2] + tree[at*2+1];
}
int query(int at, int l, int r, int val)
{
	if(l == r) return l;
	
	int mid = (l+r)/2;
	
	if(tree[at*2] >= val) return query(at*2, l, mid, val);
	else return query(at*2+1, mid+1, r, val-tree[at*2]);
}

int main()
{
	int n, q, x;
	
	cin >> n >> q;
	
	
	for(int K = 0; K < n; K++){
		scanf("%d", &x);
		update(1, 1, n, x, 1);
	}
	
	while(q--){
		scanf("%d", &x);
		
		if(x >= 1 && x <= n){
			update(1, 1, n, x, 1);
		}
		else if(x < 0){
			x = query(1, 1, n, abs(x));
			update(1, 1, n, x, -1);
		}
	}
	
	if(tree[1] == 0) cout << 0 << "\n";
	else cout << query(1, 1, n, 1) << "\n";
	
	return 0;
}
