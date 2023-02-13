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
ll a[N+5], b[N+5];
vector<ll> ara[N+5];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin >> n;
	
	
	for(int K = 1; K <= n; K++) cin >> a[K];
	for(int K = 1; K <= n; K++) cin >> b[K];
	
	for(int K = 1; K <= n; K++) ara[a[K]].push_back(K);
	for(int K = 1; K <= n; K++) ara[b[K]].push_back(K);
	
	for(int K = 1; K <= n; K++) sort(ara[K].begin(), ara[K].end());
	
	unsigned long long ans = 0;
	ll l = ara[1][0], r = ara[1][1];
	ans += l*(l-1)/2 + (n-r)*(n-r+1)/2;
	ans += (r-l-1)*(r-l)/2;
	for(int K = 2; K <= n; K++){
		if(ara[K][0] >= l && ara[K][0] <= r){
			l = min(ara[K][0], l);
			r = max(ara[K][1], r);
			continue;
		}
		if(ara[K][1] >= l && ara[K][1] <= r){
			l = min(ara[K][0], l);
			r = max(ara[K][1], r);
			continue;
		}
		
		unsigned long long mid = 0;
		if(ara[K][0] < l && r < ara[K][1]){
			mid = l-ara[K][0];
			mid *= ara[K][1]-r;
			
			ans += mid;
		}
		else if(ara[K][1] < l){
			mid = max(0ll, (l-ara[K][1]));
			mid *= max(0ll, (n-r+1));
			
			ans += mid;
		}
		else{
			//ll mid = (l-ara[K][1])*(l-ara[K][1]+1)/2;
			mid = max(0ll, (ara[K][0]-r));
			mid *= max(0ll, (l));
			
			ans += mid;
		}
		
		l = min(ara[K][0], l);
		r = max(ara[K][1], r);
		
		//cout << K << ' ' << mid << ' ' << ans << "\n";
	}
	
	ans++;
	
	cout << ans << "\n";
	
	return 0;
}





































