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
		int n, k; cin >> n >> k;
		
		int x[k], c[k]; 
		for(int K = 0; K < k; K++) cin >> x[K];
		for(int K = 0; K < k; K++) cin >> c[K];
		
		if(c[0] > x[0]){
			cout << "NO\n";
			continue;
		}
		
		string s = "";
		char ch = 'a';
		
		for(int K = 0; K < c[0]-2; K++) s += ch;
		vector<char> vec{'a', 'b', 'c'};
		int pos = 0;
		for(int K = c[0]-1; K <= x[0]; K++) s += vec[(++pos)%3];
		ch = 'd'; pos++; pos %= 3;
		
		bool ok = 1;
		for(int K = 1; K < k; K++){
			if(c[K]-(K ? c[K-1] : 0) > x[K]-(K ? x[K-1] : 0)){
				ok = 0;
				break;
			}
			
			int p = (c[K]-(K ? c[K-1] : 0));
			int g = (x[K]-(K ? x[K-1] : 0)) - p;
			
			for(int L = 0; L < p; L++) s += ch;
			ch++;
			
			for(int L = 0; L < g; L++){
				s += vec[pos];
				pos++;
				pos %= 3;
			}
		}
		
		//for(int K = (int)s.length(); K < n; K++) s += 'a';
		
		if(ok) cout << "YES\n" << s << "\n";
		else cout << "NO" << "\n";
	}
	
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
