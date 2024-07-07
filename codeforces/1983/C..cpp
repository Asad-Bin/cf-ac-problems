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

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

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
		int tot = 0;

		int a[n], b[n], c[n];
		for(int K = 0; K < n; K++){
			cin >> a[K];
			tot += a[K];
		}
		for(int K = 0; K < n; K++) cin >> b[K];
		for(int K = 0; K < n; K++) cin >> c[K];

		tot = (tot + 2)/3;

		for(int K = 1; K < n; K++){
			a[K] += a[K-1];
			b[K] += b[K-1];
			c[K] += c[K-1];
		}

		// cout << tot << '\n';
		// for(int K = 0; K < n; K++) cout << a[K] << ' ' << b[K] << ' ' << c[K] << "\n";

		vector<int> ans(6, -1);
		// memset(ans, -1, sizeof ans);
		for(int K = 0; K < n; K++){
			if(a[K] >= tot){
				int val = tot;
				
				int it = lower_bound(b+K+1, b+n, val+b[K])-b;
				if(it == n) {}
				else{
					int mid = c[n-1]-c[it];
					if(mid >= tot){
						ans = vector<int>{0, K, K+1, it, it+1, n-1};
						break;
					}
				}

				int it2 = lower_bound(c+K+1, c+n, val+c[K])-c;
				// cout << "hi " << it2 << "\n";
				if(it2 == n) {}
				else{
					int mid = b[n-1]-b[it2];
					if(mid >= tot){
						ans = vector<int>{0, K, it2+1, n-1, K+1, it2};
						break;
					}
				}
			}

			if(b[K] >= tot){
				int val = tot;
				
				int it = lower_bound(a+K+1, a+n, val+a[K])-a;
				if(it == n) {}
				else{
					int mid = c[n-1]-c[it];
					if(mid >= tot){
						ans = vector<int>{K+1, it, 0, K, it+1, n-1};
						break;
					}
				}

				int it2 = lower_bound(c+K+1, c+n, val+c[K])-c;
				if(it2 == n) {}
				else{
					int mid = a[n-1]-a[it2];
					if(mid >= tot){
						ans = vector<int>{it2+1, n-1, 0, K, K+1, it2};
						break;
					}
				}
			}

			if(c[K] >= tot){
				int val = tot;
				
				int it = lower_bound(b+K+1, b+n, val+b[K])-b;
				if(it == n) {}
				else{
					int mid = a[n-1]-a[it];
					if(mid >= tot){
						ans = vector<int>{it+1, n-1, K+1, it, 0, K};
						break;
					}
				}

				int it2 = lower_bound(a+K+1, a+n, val+a[K])-a;
				if(it2 == n) {}
				else{
					int mid = b[n-1]-b[it2];
					if(mid >= tot){
						ans = vector<int>{K+1, it2, it2+1, n-1, 0, K};
						break;
					}
				}
			}
		}

		if(ans[0] == -1) cout << -1 << "\n";
		else{
			for(int K = 0; K < 6; K++) cout << ans[K]+1 << ' ';
			cout << "\n";
		}
	}

	return 0;
}





























