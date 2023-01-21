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
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int ara[6];
		for(int K = 0; K < 6; K++) cin >> ara[K];
		
		int x, y; cin >> x >> y;
		
		
		int a = 0, b = 0;
		if(ara[0] == ara[2]){
			a = ara[4];
			
			if(ara[1] == ara[5]) b = ara[3];
			else if(ara[3] == ara[5]) b = ara[1];
		}
		else if(ara[0] == ara[4]){
			a = ara[2];
			
			if(ara[1] == ara[3]) b = ara[5];
			else if(ara[3] == ara[5]) b = ara[1];
		}
		else if(ara[2] == ara[4]){
			a = ara[0];
			
			if(ara[1] == ara[5]) b = ara[3];
			else if(ara[3] == ara[1]) b = ara[5];
		}
		
		//cout << a << ' ' << b << "\n";
		
		bool ok = 1;
		if(ara[0] == 1 && ara[1] == 1 && a == 2 && b == 2 && ara[0] != x && ara[1] != y) ok = 0;
		if(ara[2] == 1 && ara[3] == 1 && a == 2 && b == 2 && ara[2] != x && ara[3] != y) ok = 0;
		if(ara[4] == 1 && ara[5] == 1 && a == 2 && b == 2 && ara[4] != x && ara[5] != y) ok = 0;
		
		if(ara[0] == 1 && ara[1] == n && a == 2 && b == n-1 && ara[0] != x && ara[1] != y) ok = 0;
		if(ara[2] == 1 && ara[3] == n && a == 2 && b == n-1 && ara[2] != x && ara[3] != y) ok = 0;
		if(ara[4] == 1 && ara[5] == n && a == 2 && b == n-1 && ara[4] != x && ara[5] != y) ok = 0;
		
		if(ara[0] == n && ara[1] == 1 && a == n-1 && b == 2 && ara[0] != x && ara[1] != y) ok = 0;
		if(ara[2] == n && ara[3] == 1 && a == n-1 && b == 2 && ara[2] != x && ara[3] != y) ok = 0;
		if(ara[4] == n && ara[5] == 1 && a == n-1 && b == 2 && ara[4] != x && ara[5] != y) ok = 0;
		
		if(ara[0] == n && ara[1] == n && a == n-1 && b == n-1 && ara[0] != x && ara[1] != y) ok = 0;
		if(ara[2] == n && ara[3] == n && a == n-1 && b == n-1 && ara[2] != x && ara[3] != y) ok = 0;
		if(ara[4] == n && ara[5] == n && a == n-1 && b == n-1 && ara[4] != x && ara[5] != y) ok = 0;
		
		//if(ara[0] == 2 && ara[1] == 2 && a == 1 && b == 1 && ara[0] != x && ara[1] != y) ok = 0;
		//if(ara[2] == 2 && ara[3] == 2 && a == 1 && b == 1 && ara[2] != x && ara[3] != y) ok = 0;
		//if(ara[4] == 2 && ara[5] == 2 && a == 1 && b == 1 && ara[4] != x && ara[5] != y) ok = 0;
		
		//if(ara[0] == 2 && ara[1] == 7 && a == 1 && b == 8 && ara[0] != x && ara[1] != y) ok = 0;
		//if(ara[2] == 2 && ara[3] == 7 && a == 1 && b == 8 && ara[2] != x && ara[3] != y) ok = 0;
		//if(ara[4] == 2 && ara[5] == 7 && a == 1 && b == 8 && ara[4] != x && ara[5] != y) ok = 0;
		
		//if(ara[0] == 7 && ara[1] == 2 && a == 8 && b == 1 && ara[0] != x && ara[1] != y) ok = 0;
		//if(ara[2] == 7 && ara[3] == 2 && a == 8 && b == 1 && ara[2] != x && ara[3] != y) ok = 0;
		//if(ara[4] == 7 && ara[5] == 2 && a == 8 && b == 1 && ara[4] != x && ara[5] != y) ok = 0;
		
		//if(ara[0] == 7 && ara[1] == 7 && a == 8 && b == 8 && ara[0] != x && ara[1] != y) ok = 0;
		//if(ara[2] == 7 && ara[3] == 7 && a == 8 && b == 8 && ara[2] != x && ara[3] != y) ok = 0;
		//if(ara[4] == 7 && ara[5] == 7 && a == 8 && b == 8 && ara[4] != x && ara[5] != y) ok = 0;
		
		if(!ok || (abs(a-x)%2==0 && abs(b-y)%2==0)) cout << "NO\n";
		else cout << "YES\n";
	}
	
	
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

		  				  						 	 			 	 		   	