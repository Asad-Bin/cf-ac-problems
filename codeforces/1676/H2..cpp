// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MX = 2e5;
int tree[4*MX+5];

int query(int at, int l, int r, int val)
{
	if(r < val) return 0;
	if(val <= l) return tree[at];
	
	int mid = (l+r)/2;
	
	int ans = query(at*2, l, mid, val);
	ans += query(at*2+1, mid+1, r, val);
	
	return ans;
}

void update(int at, int l, int r, int val)
{
	if(l == r){
		tree[at]++;
		return;
	}
	
	int mid = (l+r)/2;
	
	if(val <= mid) update(at*2, l, mid, val);
	else update(at*2+1, mid+1, r, val);
	
	tree[at] = tree[at*2] + tree[at*2+1];
}

int main()
{
	int t, n, x;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		ll ans = 0;
		for(int K = 1; K <= 4*n; K++) tree[K] = 0;
		for(int K = 0; K < n; K++){
			cin >> x;
			
			ll mid = query(1, 1, n, x);
			
			ans += mid;
			
			update(1, 1, n, x);
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































