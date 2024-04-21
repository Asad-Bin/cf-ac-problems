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

const ll mod = 1e9+7;
ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll bigmod(ll a,ll b,ll mod){ 
	b %= (mod-1);
	a %= mod;

	if(b==0){
	 return 1;
	} 
	ll tm=bigmod(a,b/2,mod); 
	tm=(tm*tm)%mod; 
	if(b%2==1) tm=(tm*a)%mod; 
	return tm;
}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}



const int N = 3e5;
ll row[N+5], col[N+5];
ll row_pre[N+5], col_pre[N+5], fact[N+5], fct[N+5], rev[N+5];
ll n, k;
// ll dp[N+5];

ll ncr(ll a, ll b){ 
	return (fct[a] * rev[b] % mod) * rev[a-b] % mod;
	// ll x = max(a-b, b), ans=1; 
	// for(ll K=a, L=1; K>=x+1; K--, L++){ 
	// 	ans = ans * K % mod; 
	// 	ans = ans * inverse_mod(L, mod) % mod;
	// } 
	// return ans;
}

ll calc(int at)
{
	// if(at == 0) return 1;
	// if(at == 1) return 0;
	// if(at < 0) return 0;

	if(at&1) return 0;
	else{
		return fact[at-1];
	}
	// if(at)

	ll ans = 1;

	// while(at >= 2){
	// 	ans = (at-1)*ans%mod;
	// 	// ans %= mod;
	// 	at -= 2;
	// }

	// ans = calc(at-1);

	// if(!row[at] && !col[at]){
	// 	ans = calc(at+1);
	// }

	// if(row[at] && col[at]){
	// 	ans = calc(at+1);
	// }
	// else if(row[at]){
	// 	ans += (n-row_pre[n]) * calc(at+1) % mod;
	// 	ans %= mod;
	// }
	// // else if(col[at]){
	// // 	ans += (n-col_pre[n]) * calc(at+1) % mod;
	// // 	ans %= mod;
	// // }
	// else{
	// 	ans += (n-col_pre[n]-1) * calc(at+1) % mod;
	// 	ans %= mod;
	// }

	// cout << at << ' ' << ans << "\n";

	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fact[0] = fact[1] = 1;
	for(int K = 3; K <= N; K+=2) fact[K] = fact[K-2] * K % mod;

	fct[0] = fct[1] = 1;
	for(int K = 2; K <= N; K++) fct[K] = fct[K-1] * K % mod;
	rev[N] = inverse_mod(fct[N], mod);
	for(int K = N-1; K >= 0; K--){
		rev[K] = rev[K+1] * (K+1) % mod;
	}

	// cout << ncr(5, 2) << "\n";

	int t = 1; 
	cin >> t;
	for(int cs = 1; cs <= t; cs++){
		// cout << "Case " << cs << ": ";

		cin >> n >> k;
		for(int K = 1; K <= n; K++){
			row[K] = col[K] = 0;
			// dp[K] = -1;
		}

		for(int K = 0; K < k; K++){
			int x, y; cin >> x >> y;
			row[x] = col[y] = row[y] = col[x] = 1;
		}

		// row_pre[1] = row[1]; col_pre[1] = col[1];
		// for(int K = 2; K <= n; K++){
		// 	row_pre[K] = row[K] + row_pre[K-1];
		// 	col_pre[K] = col[K] + col_pre[K-1];
		// }
		ll x = 0, cnt = n;
		for(int K = 1; K <= n; K++){
			if(row[K]) cnt--;
			if(!row[K] && !col[K]) x++;
		}

		// for(int K = 1; K <= n; K++) cout << K << ' ' << col_pre[K] << ' ' << row_pre[K] << "\n";

		// cout << x << cnt << '\n';
		ll ans = 0;
		for(int K = 0; K <= x; K++){
			ll m = (cnt-K)/2;
			ans += ((ncr(x, K) * modpow(2, m, mod)% mod) * calc(cnt-K) % mod);
			ans %= mod;
			// cout << K << ' ' << calc(cnt-K) << "\n";
		}
		cout << (ans+1)%mod << "\n";
	}

	return 0;
}





























