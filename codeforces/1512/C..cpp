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


void task()
{
	// Code here.. ..
	
	// a -> 0, b -> 1;
	
	int t, a, b, n;
	string s;
	
	cin >> t;
	while(t--){
		cin >> a >> b >> s;
		n = a+b;
		
		if((a%2==1 && b%2==1) || (n%2==0 && (a%2==1 || b%2==1)) || (n%2==1 && a%2==0 && b%2==0)){
			cout << -1 << "\n";
			continue;
		}
		
		bool ok = 1;
		for(int K=0; K<n/2; K++){
			if(s[K]!=s[n-1-K] && s[K]!='?' && s[n-1-K]!='?'){
				ok = 0;
				break;
			}
			
			if(s[K]!='?' && s[n-1-K]=='?') s[n-1-K] = s[K];
			else if(s[K]=='?' && s[n-1-K]!='?') s[K] = s[n-1-K];
		}
		if(n%2==1 && s[(n+1)/2-1]=='?'){
			if(a%2==1) s[(n+1)/2-1] = '0';
			else if(b%2==1) s[(n+1)/2-1] = '1';
			else ok = 0;
		}
		
		if(!ok){
			cout << -1 << "\n";
			continue;
		}
		
		for(int K=0; K<n; K++){
			if(s[K]=='0') a--;
			else if(s[K]=='1') b--;
		}
		
		if(a<0 || b<0){
			cout << -1 << "\n";
			continue;
		}
		
		for(int K=0; K<n/2; K++){
			if(s[K]=='?'){
				if(a>0){
					s[K] = s[n-1-K] = '0';
					a -= 2;
				}
				else{
					s[K] = s[n-1-K] = '1';
					b -= 2;
				}
			}
		}
		
		if(a<0 || b<0) cout << -1 << "\n";
		else cout << s << "\n";
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
