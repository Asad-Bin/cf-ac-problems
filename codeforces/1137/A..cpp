//...Bismillahir Rahmanir Rahim...
// ***Asad Bin Saber***
 
#include <bits/stdc++.h>
using namespace std;
 
// typedefs...
typedef long long            ll;
typedef unsigned long long   ull;
typedef pair<int, int>       pii;
typedef vector<int>          vi;
typedef vector<ll>           vl;
typedef pair<ll, ll>         pll;
 
// constants...
//const double PI = acos(-1);
const int    mod = 1e9+7; // 998244353;
const int    MXI = 1e9+5;
const ll     MXL = 1e18+5;
 
// defines...
#define MP             make_pair
#define PB             push_back
#define fi             first
#define se             second
#define sz(x)          (int)x.size()
#define all(x)         begin(x), end(x)
#define si(a)          scanf("%d", &a)
#define sii(a, b)      scanf("%d%d", &a, &b)
#define siii(a, b, c)  scanf("%d%d%d", &a, &b, &c)
#define precise_impact cout<<setprecision(6)<<fixed;
 
// chess moves...
// int dx[] = {+0, +0, -1, +1}; ///Up-down, Left-Right
// int dy[] = {+1, -1, +0, +0};
// int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's Move
// int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
// int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2}; ///Knight's Move
// int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};
 
// structs...
struct hash_pair{ template <class T1, class T2> size_t operator()(const pair<T1, T2>& p) const{ auto hash1 = hash<T1>{}(p.first); auto hash2 = hash<T2>{}(p.second); return hash1 ^ hash2;} };
 
// functions...
ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll bigmod(ll a, ll p, ll M)
{
	// If 'M' is a prime number, then we can speed up it just by calculating "a^(p%(M-1))";
	p %= (M-1);
	
	ll result = 1LL;
	while(p>0LL){
		if(p&1LL) result = result * a % M;
		a = a * a % M;
		p>>=1LL;
	}
	return result;
}
ll inverse(ll a, ll M){
	if(gcd(a, M)==1) return bigmod(a, M-2, M) % M; // (ax)%M = 1
	return 1;
}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K % mod; ans = ans*inverse(L, mod)%mod;} return ans;}
ll egcd(ll a,ll b,ll &x,ll &y){
	if(a==0){
		x=0; y=1;
		return b;
	}
	
	ll x1,y1;
	ll d=egcd(b%a,a,x1,y1);
	x=y1-(b/a)*x1; y=x1;
	return d;
}
void pbin(int n)
{
	vector<int> vv;
	while(n){
		vv.PB(n%2);
		n >>= 1;
	}
	for(int K=sz(vv); K<=5; K++) vv.PB(0);
	reverse(all(vv));
	for(auto x:vv) cout << x;
	cout << "\n";
}


vector<vi> Lr(1005), Lc(1005);
int ara[1005][1005];
void task()
{
	// Code here.. ..
	
	int n, m;
	
	cin >> n >> m;
	
	for(int K=0; K<n; K++){
		for(int L=0; L<m; L++){
			cin >> ara[K][L];
			Lr[K].PB(ara[K][L]);
			Lc[L].PB(ara[K][L]);
		}
	}
	
	for(int K=0; K<n; K++) sort(all(Lr[K]));
	for(int L=0; L<m; L++) sort(all(Lc[L]));
	
	for(int K=0; K<n; K++){
		for(int L=0; L<sz(Lr[K])-1; L++){
			if(Lr[K][L]==Lr[K][L+1]) Lr[K].erase(Lr[K].begin()+L), L--;
		}
	}
	
	for(int L=0; L<m; L++){
		for(int K=0; K<sz(Lc[L])-1; K++){
			if(Lc[L][K]==Lc[L][K+1]) Lc[L].erase(Lc[L].begin()+K), K--;
		}
	}
	
	for(int K=0; K<n; K++){
		for(int L=0; L<m; L++){
			int x = lower_bound(all(Lr[K]), ara[K][L]) - Lr[K].begin() - 1;
			int y = lower_bound(all(Lc[L]), ara[K][L]) - Lc[L].begin() - 1;
			
			int p = max(x, y);
			
			//x = sz(Lr[K]) - (Lr[K].upper_bound(all(Lr[K]), ara[K][L])-Lr[K].begin());
			//y = sz(Lc[L]) - (Lc[L].upper_bound(all(Lc[L]), ara[K][L])-Lc[L].begin());
			
			int q = max(sz(Lr[K])-x-1, sz(Lc[L])-y-1);
			
			cout << p+q+1 << ' ';
		}
		cout << "\n";
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	task();
	return 0;
}
