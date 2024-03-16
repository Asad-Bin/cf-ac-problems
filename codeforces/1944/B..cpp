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



signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	cin >> t;
	for(int cs = 1; cs <= t; cs++){
		// cout << "Case " << cs << ": ";

		int n, k; cin >> n >> k;

		int ara[2*n+1]; //ara[2*n] = -1;
		for(int K = 0; K < 2*n; K++) cin >> ara[K];

		sort(ara, ara+n);
		sort(ara+n, ara+2*n);

		vector<int> v1, v2;
		int i = 0;
		for(int K = 0; K < n; K++){
			if(K + 1 < n && ara[K] == ara[K+1]){
				// if(i + 2 > 2*k && !v2.empty()){
				// 	v2.pop_back();
				// 	i--;
				// }
				// else i/f(i+2 > 2*k) continue;

				v1.push_back(ara[K]);
				v1.push_back(ara[K]);
				// i += 2;
				K++;
			}
			else{
				v2.push_back(ara[K]);
				// i++;
			}

			// if(i == 2*k) break;
		}

		// for(auto it: v1) cout << it << ' ';
		// for(auto it: v2) cout << it << ' ';
		// cout << "\n";

		vector<int> v3, v4;
		i = 0;
		for(int K = n; K < 2*n; K++){
			if(K+1 < 2*n && ara[K] == ara[K+1]){
				// if(i + 2 > 2*k && !v2.empty()){
				// 	v4.pop_back();
				// 	// i--;
				// }
				// else if(i+2 > 2*k) continue;

				v3.push_back(ara[K]);
				v3.push_back(ara[K]);
				// i += 2;
				K++;
			}
			else{
				v4.push_back(ara[K]);
				// i++;
			}

			// if(i == 2*k) break;
		}

		// for(auto it: v1) cout << it << ' ';
		// for(auto it: v2) cout << it << ' ';
		// cout << "\n";

		k *= 2;

		vector<int> ans1, ans2;
		while(k){
			if(!v1.empty()){
				ans1.push_back(v1.back());
				ans1.push_back(v1.back());
				v1.pop_back();
				v1.pop_back();

				ans2.push_back(v3.back());
				ans2.push_back(v3.back());
				v3.pop_back();
				v3.pop_back();

				k -= 2;
			}
			else{
				ans1.push_back(v2.back());
				ans2.push_back(v2.back());

				v2.pop_back();
				k--;
			}
		}

		for(auto it: ans1 ) cout << it << ' ';
		cout << "\n";
		for(auto it: ans2 ) cout << it << ' ';
		cout << "\n";
	}

	return 0;
}





























