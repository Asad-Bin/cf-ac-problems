// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 1e5;
int ro[MX+5], co[MX+5], tree[4*MX+5], tree0[4*MX+5];
void update(int at, int l, int r, int i, int val)
{
	if(l == r){
		ro[l] += val;
		//cout << l << ' ' << ro[l] << ' ' << val << "--\n";
		if(ro[l]) tree[at] = 1;
		else tree[at] = 0;
		
		return;
	}
	
	int mid = (l+r)/2;
	
	if(i <= mid) update(at*2, l, mid, i, val);
	else update(at*2+1, mid+1, r, i, val);
	
	tree[at] = tree[at*2] + tree[at*2+1];
	//cout << l << ' ' << r << ' ' << tree[at]<< "++\n";
}
void update0(int at, int l, int r, int i, int val)
{
	if(l == r){
		co[l] += val;
		if(co[l]) tree0[at] = 1;
		else tree0[at] = 0;
		
		return;
	}
	
	int mid = (l+r)/2;
	
	if(i <= mid) update0(at*2, l, mid, i, val);
	else update0(at*2+1, mid+1, r, i, val);
	
	tree0[at] = tree0[at*2] + tree0[at*2+1];
}

int query(int at, int l, int r, int L, int R)
{
	if(L <= l && r <= R) return tree[at];
	if(r < L || R < l) return 0;
	
	int mid = (l+r)/2;
	
	int ans = 0;
	ans += query(at*2, l, mid, L, R);
	ans += query(at*2+1, mid+1, r, L, R);
	
	return ans;
}
int query0(int at, int l, int r, int L, int R)
{
	if(L <= l && r <= R) return tree0[at];
	if(r < L || R < l) return 0;
	
	int mid = (l+r)/2;
	
	int ans = 0;
	ans += query0(at*2, l, mid, L, R);
	ans += query0(at*2+1, mid+1, r, L, R);
	
	return ans;
}

int main()
{
	int n, q, t, x, y, a, b;
	
	memset(ro, 0, sizeof ro);
	memset(co, 0, sizeof co);
	memset(tree, 0, sizeof tree);
	memset(tree0, 0, sizeof tree0);
	
	scanf("%d%d", &n, &q);
	
	while(q--){
		scanf("%d", &t);
		
		if(t == 1){
			scanf("%d%d", &x, &y);
			
			update(1, 1, n, x, 1);
			update0(1, 1, n, y, 1);
		}
		else if(t == 2){
			scanf("%d%d", &x, &y);
			
			update(1, 1, n, x, -1);
			update0(1, 1, n, y, -1);
		}
		else{
			scanf("%d%d%d%d", &x, &y, &a, &b);
			
			bool ok = 0;
			
			int mid = query(1, 1, n, min(x, a), max(x, a));
			if(abs(x-a)+1 == mid) ok = 1;
			//cout << min(x, a) << ' ' << max(x, a) << ' ' << mid << "\n";
			
			mid = query0(1, 1, n, min(b, y), max(y, b));
			if(abs(y-b)+1 == mid) ok = 1;
			//cout << min(y, b) << ' ' << max(y, b) << ' ' << mid << "\n";
			
			if(ok) printf("Yes\n");
			else printf("No\n");
		}
	}
	
	return 0;
}




















































