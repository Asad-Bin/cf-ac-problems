// . . . Bismillahir Rahmanir Rahim . . .


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg_out cout
#define debug(...) dbg_out << "DBG )> "; __f(#__VA_ARGS__, __VA_ARGS__);
template<typename T1, typename T2> ostream& operator<<(ostream& out, pair<T1, T2> pr) { out << "{ " << pr.first << ", " << pr.second << " }"; return out; }
template<typename T1> ostream& operator<<(ostream& out, vector<T1> vec) { out << "{ "; for (auto &x: vec) out << x << ", "; out << "}"; return out; }
template<typename T1, size_t size> ostream& operator<<(ostream& out, array<T1, size> arr) { out << "{ "; for (auto &x: arr) out << x << ", "; out << "}"; return out; }
template<typename T1, typename T2> ostream& operator<<(ostream& out, map<T1, T2> mp) { out << "{ ";for (auto &x: mp) out << x.first << ": " << x.second <<  ", "; out << "}"; return out; }
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { while (isspace(name[0])) name++; (isalpha(name[0]) || name[0] == '_') ? dbg_out << name << ": " << arg1 << "\n" : dbg_out << arg1 << "\n"; dbg_out.flush();}
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) { const char *comma = strchr(names + 1, ','); while (isspace(names[0])) names++; (isalpha(names[0]) || names[0] == '_') ? dbg_out.write(names, comma - names) << ": " << arg1 << " | " : dbg_out << arg1 << " | "; __f(comma + 1, args...);}
#else
#define debug(...)
#endif

ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}
ll bigmod(ll a,ll b,ll mod){ if(b==0){ return 1;} ll tm=bigmod(a,b/2,mod); tm=(tm*tm)%mod; if(b%2==1) tm=(tm*a)%mod; return tm;}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}


const int N = 2e5;
//int s[N+5];
int n;
//int a[N+5], b[N+5];
//int bs(int h, int x) {
	//int l = 1, ans = 0;
	
	//while(l <= h) {
		//int m = (l+h)>>1;
		
		//if(x <= a[b[m]]) { ans = m; l = m+1; }
		//else h = m-1;
	//}
	//return ans+1;
//}

//int lis() {
	//int len = 0;
	//int p[n];
	
	//for(int i = 0; i < n; ++i) {
		//int tmp = bs(len, a[i]);
		
		//b[tmp] = i;
		//p[i] = b[tmp-1];
		//len = max(tmp, len);
	//}
	
	//int k = b[len];
	
	//for(int i = len-1; i >= 0; --i) {
		//s[i] = a[k];
		//k = p[k];
	//}
	
	////cout << "ara : ";
	////for(int i = 0; i < len; ++i) cout << s[i] << ' '; // prints answer array.
	////cout << endl;
	
	//return len;             // returns answer length();
//}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--){
		cin >> n;
		
		int a[n];
		
		//for(int K = 0; K <=n; K++) b[K] = 0;
		for(int K = 0; K < n; K++) cin >> a[K];
		
		//int dp[n][2], ara[n][2];
		//ara[n-1][0] = ara[n-1][1] = -1;
		
		//for(int K = n-1; K >= 0; K--){
			//;
		//}
		
		vector<int> b, c; 
		
		for(int K = 0; K < n; K++){
			if(b.empty()){
				b.push_back(a[K]);
			}
			else if(c.empty()){
				if(a[K] <= b.back()) b.push_back(a[K]);
				else c.push_back(a[K]);
			}
			else if(a[K] <= min(b.back(), c.back())){
				if(b.back() <= c.back()) b.push_back(a[K]);
				else c.push_back(a[K]);
			}
			else if(max(b.back(), c.back()) < a[K]){
				if(b.back() <= c.back()) b.push_back(a[K]);
				else c.push_back(a[K]);
			}
			else{
				if(b.back() >= c.back()) b.push_back(a[K]);
				else c.push_back(a[K]);
			}
		}
		
		int ans = 0;
		for(int K = 0; K < (int)b.size()-1; K++) if(b[K] < b[K+1]) ans++;
		for(int K = 0; K < (int)c.size()-1; K++) if(c[K] < c[K+1]) ans++;
		
		cout << ans << "\n";
	}
	
	return 0;
}





































