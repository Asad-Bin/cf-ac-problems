// . . . Bismillahir Rahmanir Rahim . . .
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;


const int MX = 1e5;
ll tree[4*MX+5], lazy[4*MX+5], res[MX+5];

void build(int at, int l, int r)
{
	if(l == r){
		tree[at] = res[l];
		return;
	}
	
	int mid = (l+r)/2;
	
	build(at*2, l, mid);
	build(at*2+1, mid+1, r);
	
	tree[at] = tree[at*2] + tree[at*2+1];
}
void prop(int at, int l, int r, int mid)
{
	tree[at*2] += lazy[at]*(mid-l+1);
	tree[at*2+1] += lazy[at]*(r-mid);
	lazy[at*2] += lazy[at];
	lazy[at*2+1] += lazy[at];
	
	lazy[at] = 0;
}
void update(int at, int l, int r, int L, int R, ll val)
{
	if(r < L || R < l) return;
	if(L <= l && r <= R){
		lazy[at] += val;
		tree[at] += val*(r-l+1);
		return;
	}
	
	
	int mid = (l+r)/2;
	prop(at, l, r, mid);
	
	update(at*2, l, mid, L, R, val);
	update(at*2+1, mid+1, r, L, R, val);
	
	tree[at] = tree[at*2] + tree[at*2+1];
	//cout << at << ' ' << l << ' ' << r << ' ' << tree[at] << "\n";
}

int main() 
{
	ll n, m;
	
	cin >> n >> m;
	
	ll ara[n+1];
	memset(lazy, 0LL, sizeof lazy);
	
	for(int K = 1; K <= n; K++) cin >> ara[K];
	
	res[1] = 1;
	for(int K = 2; K <= n; K++){
		res[K] = res[K-1] + 1;
		if(ara[K] != ara[K-1]) res[K] += K-1;
		
		debug({K, res[K]});
		//cout << K << ' ' << ara[K] << ' ' << res[K] << "\n";
		
		;;
	}
	
	ll i, x;
	
	build(1, 1, n); // build with res;
	//c//out << tree[1] << "\n";
	
	while(m--){
		cin >> i >> x;
		//cout << "i = " << i << ' ' << x << "\n";
		
		if(ara[i] != ara[i-1]){
			if(ara[i-1] == x){
				update(1, 1, n, i, n, -(i-1)); // value = i-1 will be reduced
			}
			else{
				;
			}
			
			
			if(ara[i+1] == x){
				if(ara[i+1] != ara[i]) update(1, 1, n, i+1, n, -i);
			}
			else{
				if(ara[i+1] == ara[i]) update(1, 1, n, i+1, n, i);
			}
		}
		else{
			if(ara[i-1] != x){
				update(1, 1, n, i, n, i-1);
			}
			
			
			if(ara[i+1] == x){
				if(ara[i+1] != ara[i]) update(1, 1, n, i+1, n, -i);
			}
			else{
				if(ara[i+1] == ara[i]) update(1, 1, n, i+1, n, i);
			}
		}
		
		cout << tree[1] << "\n";
		
		
		ara[i] = x;
	}
	
	
	return 0;
}

