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



const int N = 1000;
ll ara[N+5][3];
int n, m; 
const ll inf = 1e9+7;
ll dp[22][(1<<10)+5];

ll calc(int at, int val)
{
	if(val == 0) return  0;
	if(at == 20){
		if(val) return inf;
		return 0;
	}
	
	if(dp[at][val] != -1) return dp[at][val];
	
	//int ans = calc(at+1, val);
	//ans = min(ans, calc(at+1, (val^(val&ara[at][1])) | ara[at][2]) + ara[at][0]);
	
	ll ans = inf;
	for(int K = 0; K < m; K++){
		ans = min(ans, calc(at+1, (val^(val&ara[K][1])) | ara[K][2]) + ara[K][0]);
	}
	
	//cout << at << ' ' << val << "\n";
	
	return dp[at][val] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		string s; cin >> s;
		int num = 0;
		for(int K = 0; K < n; K++) if(s[K] == '1') num |= (1<<K);
		//cout << "s = " << num << "\n";
		
		for(int K = 0; K < m; K++){
			cin >> ara[K][0];
			cin >> s;
			ara[K][1] = 0;
			for(int L = 0; L < n; L++) if(s[L] == '1') ara[K][1] |= (1<<L);
			
			cin >> s;
			ara[K][2] = 0;
			for(int L = 0; L < n; L++) if(s[L] == '1') ara[K][2] |= (1<<L);
		}
		
		memset(dp, -1ll, sizeof dp);
		
		ll ans = calc(0, num);
		if(ans == inf) cout << -1 << "\n";
		else cout << ans << "\n";
	}
	
	return 0;
}





































