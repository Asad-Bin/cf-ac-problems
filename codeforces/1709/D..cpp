// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 2e5;
ll ara[MX+5], tree[4*MX+5];

void build(int at, int l, int r)
{
	if(l == r){
		tree[at] = ara[l];
		
		return;
	}
	
	int mid = (l+r)/2;
	
	build(at*2, l, mid);
	build(at*2+1, mid+1, r);
	
	tree[at] = max(tree[at*2], tree[at*2+1]);
}
int query(int at, int l, int r, int L, int R)
{
	if(L > R) return 0;
	if(r < L || R < l) return 0;
	if(L <= l && r <= R) return tree[at];
	
	int mid = (l+r)/2;
	
	return max(query(at*2, l, mid, L, R), query(at*2+1, mid+1, r, L, R));
}

int main()
{ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n, m;
	
	cin >> n >> m;
	
	for(int K = 1; K <= m; K++) cin >> ara[K];
	
	build(1, 1, m);
	
	ll q, x1, y1, x2, y2, k;
	
	cin >> q;
	while(q--){
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		
		if(abs(y1-y2)%k != 0 || abs(x1-x2)%k != 0){
			cout << "NO\n";
			continue;
		}
		
		ll val = 0;
		if(min(y1, y2) + 1 < max(y1, y2)) val = query(1, 1, m, min(y1, y2)+1, max(y1, y2)-1);
		else val = 0;
		//cout << y1 << ' ' << y2 << ' ' << val << "\n";
		
		ll x = (max(val+1, max(x1, x2)) - min(x1, x2) + k - 1)/k;
		//cout << x << "\n";
		
		if((ll)min(x1, x2)+k*x <= (ll)n && (min(x1, x2)+k*x - max(x1, x2) == 0 || (min(x1, x2)+k*x - max(x1, x2))%k==0) && abs(y1-y2)%k==0) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}




















































