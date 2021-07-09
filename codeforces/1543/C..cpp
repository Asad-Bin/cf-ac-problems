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
const double PI = acos(-1);
const int    mod = 1e9+7; // 998244353;
const int    MXI = 1e9+5;
const ll     MXL = 1e18+5;
const double eps = 1e-9;

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
#define sl(a)          scanf("%lld", &a)
#define sll(a, b)      scanf("%lld%lld", &a, &b)
#define slll(a, b, c)  scanf("%lld%lld%lld", &a, &b, &c)
#define precise_impact cout<<setprecision(12)<<fixed;

// chess moves...
// int dx[] = {+0, +0, -1, +1}; ///Up-down, Left-Right
// int dy[] = {+1, -1, +0, +0};
// int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's Move
// int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
// int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2}; ///Knight's Move
// int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};

// structs...
struct hash_pair{ template <class T1, class T2> size_t operator()(const pair<T1, T2>& p) const{ auto hash1 = hash<T1>{}(p.first); auto hash2 = hash<T2>{}(p.second); return hash1 ^ hash2;}};

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
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K % mod; ans = ans * inverse(L, mod) % mod;} return ans;}
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


const long double scale = 1e+6;
long double calc(int c, int m, int p, int v)
{
	long double ans = p/scale;
	
	if(c>0){
		if(c>v){
			if(m>0) 
				ans += (c/scale)*(1+calc(c-v, m+v/2, p+v/2, v));
			else 
				ans += (c/scale)*(1+calc(c-v, 0, p+v, v));
		}
		else{
			if(m>0) 
				ans += (c/scale)*(1+calc(0, m+c/2, p+c/2, v));
			else
				ans += (c/scale)*(1+calc(0, 0, p+c, v));
		}
	}
	if(m>0){
		if(m>v){
			if(c>0) 
				ans += (m/scale)*(1+calc(c+v/2, m-v, p+v/2, v));
			else
				ans += (m/scale)*(1+calc(0, m-v, p+v, v));
		}
		else{
			if(c>0)
				ans += (m/scale)*(1+calc(c+m/2, 0, p+m/2, v));
			else 
				ans += (m/scale)*(1+calc(0, 0, p+m, v));
		}
	}	
	return ans;
}
void task()
{
	// Code here.. ..
	
	int t;
	long double cd, md, pd, vd;
	
	cin >> t;
	while(t--){
		cin >> cd >> md >> pd >> vd;
		
		int c = round(cd*scale);
		int m = round(md*scale);
		int p = round(pd*scale);
		int v = round(vd*scale);
		long double ans = calc(c, m, p, v);
		precise_impact;
		cout << ans << "\n";
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














