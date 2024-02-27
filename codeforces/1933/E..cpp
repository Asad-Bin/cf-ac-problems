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


#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	cin >> t;
	for(int cs = 1; cs <= t; cs++){
		// cout << "Case " << cs << ": ";

		int n; cin >> n;

		int ara[n];
		for(int K = 0; K  < n; K++) cin >> ara[K];

		int sum[n]; sum[0] = ara[0];
		for(int K = 1; K < n; K++) sum[K] = ara[K] + sum[K-1];

		int q; cin >> q;
		while(q--){
			int a, u; cin >> a >> u; a--;

			int l = a, r = n-1, ans = 0, mx = -1e18;

			while(l < r-2){
				int mid1 = (2*l + r)/3;
				int mid2 = (l + 2*r)/3;


				int val1 = sum[mid1]-(a ? sum[a-1] : 0);
				val1 = val1 * u - val1 * (val1-1)/2;

				int val2 = sum[mid2]-(a ? sum[a-1] : 0);
				val2 = val2 * u - val2 * (val2-1)/2;

				if(val1 < val2){
					l = mid1;
					// mx = val2;
					// ans = mid1;
					// ans = mid2;
				}
				else if(mid1 == mid2){
					l = mid1;
					r = mid2;
					// ans = mid1;
				}
				else{
					r = mid2;
					// mx = val1;
					// ans = mid1;
				}
			}
			// ans = l;

			l = max(l, a);
			r = min(r, n-1);

			ans = l;
			for(int K = l; K <= r; K++){
				int q = sum[K] - (a ? sum[a-1] : 0);
				q = q*u - q*(q-1)/2;

				if(q > mx){
					mx = q;
					ans = K;
				}
			}

			cout << ans+1 << " ";



			// int p = sum[ans] - (a ? sum[a-1] : 0);
			// p = p*u - p*(p-1)/2;

			// r = sum[n-1] - (a ? sum[a-1] : 0);
			// r = r*u - r*(r-1)/2;


			// if(p > q && p >= r)  cout << ans+1 << ' ' ;
			// else if(q >= p && q >= r) cout << a+1 << ' ';
			// else cout << n << ' ';
		}
		cout << "\n";
	}

	return 0;
}





























