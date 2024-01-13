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


vector<ll> primes;
vector<bool> mark(502);
void sieve(int n)
{
    int i, j, limit = sqrt(n*1.) + 2;

    mark[1] = 1;

    for(i = 4; i<=n; i+=2) mark[i] = 1;

    primes.push_back(2);

    for(i = 3; i <= n; i += 2)
    {
            if(!mark[i])
            {
             primes.push_back(i);

              if(i<=limit)
               {
                    for(j = i*i; j <= n; j += i*2)
                    {
                            mark[j] = 1;
                    }
               }
            }
    }
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	sieve(500);
	ll pr_sz = (int)primes.size();

	int t = 1; 
	cin >> t;
	for(int cs = 1; cs <= t; cs++){
		// cout << "Case " << cs << ": ";

		ll n; cin >> n;

		vector<ll> v;
		for(ll K = 1; K*K <= n; K++){
			if(n % K == 0){
				v.push_back(K);
				if(K != n/K) v.push_back(n/K);
			}
		}

		ll ara[n];
		for(ll K = 0; K < n; K++) cin >> ara[K];

		// sort(v.begin(), v.end());
		ll ans = 0;

		for(auto k: v){
			// vector<int> cnt(n+2, 0);
			// int extra = 0;
			// vector<int> mrk(n, 0);

			ll g = 0;
			for(ll K = 0; K+k < n; K++){
				ll x = ara[K]-ara[K+k];

				if(x < 0) x *= -1;

				// if(x == 0){
				// 	extra++;
				// }
				if(x == 1){
					// ss.clear()
					g = -1;
					break;
				}
				g = gcd(g, x);
			}
			// cout << k << ' ' << g << "\n";

			if(g == 0){
				ans++;
				continue;
			}
			ll x = g;
			// int cnt = 0;
			// 	for(ll L = 0; L < pr_sz && primes[L]*primes[L] <= x; L++){
			// 		if(x % primes[L] == 0){
			// 			cnt++;
			// 			while(x % primes[L] == 0){
			// 				x /= primes[L];
			// 			}
			// 		}
			// 	}
			// 	if(x > 1){
			// 		cnt++;
			// 	}
			// }

			// bool ok = 0;
			// for(int K = 0; K <= n+1; K++) if(cnt[K]+extra == n-k) ok = 1;

			if(g > 1) ans++;
		}

		cout << ans << "\n";
	}

	return 0;
}





























