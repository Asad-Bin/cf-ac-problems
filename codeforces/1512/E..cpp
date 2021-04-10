//...Bismillahir Rahmanir Rahim...

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
const int mod = 1e9+7; // 998244353;
const int MXI = 1e9+5;
const ll  MXL = 1e18+5;
 
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
ll comb(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}
ll bigmod(ll a,ll b){ if(b==0){ return 1;} ll tm=bigmod(a,b/2); tm=(tm*tm)%mod; if(b%2==1) tm=(tm*a)%mod; return tm;}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}


int ara[505];
bool mark[505];
void task()
{
	// Code here.. ..
	
	int t, n, l, r, s, d;
	
	cin >> t;
	while(t--){
		cin >> n >> l >> r >> s;
		
		d = s;
		
		int x = 1;
		bool ok = 1;
		for(int K=l; K<=r; K++){
			if(K==r){
				ara[K] = min(d, n);
				d -= ara[K];
				
				if(d>0){
					x = n-1;
					for(int L=K-1; L>=l; L--){
						d += ara[L];
						ara[L] = min(d, x);
						d -= ara[L];
						x--;
						if(d==0) break;
					}
				}
				
				if(d>0){
					ok = 0;
					break;
				}
				
				continue;
			}
			
			ara[K] = x;
			d -= x;
			x++;
			if(d<=0){
				ok = 0;
				break;
			}
		}
		
		memset(mark, 0, sizeof mark);
		for(int K=l; K<=r; K++){
			if(mark[ara[K]]){
				ok = 0;
				break;
			}
			mark[ara[K]] = 1;
		}
		
		if(!ok){
			cout << -1 << "\n";
			continue;
		}
		
		int i = 1;
		for(int K=1; K<l; K++){
			while(mark[i]) i++;
			ara[K] = i;
			i++;
		}
		for(int K=r+1; K<=n; K++){
			while(mark[i]) i++;
			ara[K] = i;
			i++;
		}
		
		for(int K=1; K<=n; K++) cout << ara[K] << ' ';
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
