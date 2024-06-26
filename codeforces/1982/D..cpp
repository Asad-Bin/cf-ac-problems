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



// bool calc(int at, ll sum)
// {
// 	bool ok = 0;

// 	if(ara[at] > 0 && sum < 0){
// 		ok |= calc(at, sum+ara[at]);
// 		ok |= calc(at+1, sum);
// 		ok |= calc(at+1, sum+ara[at]);
// 	}
// 	if(ara[at] < 0 && sum > 0){
// 		ok |= calc(at, sum+ara[at]);
// 		ok |= calc(at+1, sum);
// 		ok |= calc(at+1, sum+ara[at]);
// 	}
	
// 	return dp[{at, sum}] = ok;
// }
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	cin >> t;
	for(int cs = 1; cs <= t; cs++){
		// cout << "Case " << cs << ": ";

		ll n, m, k; cin >> n >> m >> k;

		ll ara[n][m];
		for(int K = 0; K < n; K++){
			for(int L = 0; L < m; L++) cin >> ara[K][L];
		}

		string s[n];
		for(int K = 0; K < n; K++){
			cin >> s[K];
		}

		ll a = 0, b = 0;

		int pre_z[n][m];
		for(int K = 0; K < n; K++){
			for(int L = 0; L < m; L++){
				if(s[K][L] == '0') pre_z[K][L] = 1;
				else pre_z[K][L] = 0;

				if(K) pre_z[K][L] += pre_z[K-1][L];
				if(L) pre_z[K][L] += pre_z[K][L-1];
				if(K && L) pre_z[K][L] -= pre_z[K-1][L-1];
// 
				// cout << K << L << ' ' << pre_z[K][L] << "\n";

				if(s[K][L] == '1') a += ara[K][L];
				else b += ara[K][L];
			}
		}
		int pre_o[n][m];
		for(int K = 0; K < n; K++){
			for(int L = 0; L < m; L++){
				if(s[K][L] == '1') pre_o[K][L] = 1;
				else pre_o[K][L] = 0;

				if(K) pre_o[K][L] += pre_o[K-1][L];
				if(L) pre_o[K][L] += pre_o[K][L-1];
				if(K && L) pre_o[K][L] -= pre_o[K-1][L-1];
			}
		}

		if( a == b){
			cout << "YES\n";
			continue;
		}

		vector<ll> v;
		set<int> ss;
		for(int K = 0; K < n; K++){
			for(int L = 0; L < m; L++){
				int i = K+k-1, j = L+k-1;
				if(i >= n || j >= m) continue;


				ll x = pre_o[i][j];
				if(K) x -= pre_o[K-1][j];
				if(L) x -= pre_o[i][L-1];
				if(K && L) x += pre_o[K-1][L-1];


				ll y = pre_z[i][j];
				if(K) y -= pre_z[K-1][j];
				if(L) y -= pre_z[i][L-1];
				if(K && L) y += pre_z[K-1][L-1];

				// cout << i << j << ' ' << K << L << ' ' << x << ' ' << y << "\n";

				if(x == y) continue;

				// if(x > y){
				// 	if(a < b) v.push_back(x-y);
				// 	else v.push_back(y-x);
				// }
				// else{
				// 	if(a > b) v.push_back(x-y);
				// 	else v.push_back(y-x);
				// }
				ss.insert(abs(x-y));
			}
		}

		// for(auto it: v) ss.insert(it);
		v.clear();
		for(auto it: ss) v.push_back(it);

		if(v.empty()){
			cout << "NO\n";
			continue;
		}
		if(v.size()==1){
			cout << (abs(a-b)%v[0]==0?"YES\n": "NO\n");
			continue;
		}

		ll ans = 0;
		// for(int K = 0; K < v.size()-1; K++){
		// 	for(int L = K+1; L < v.size(); L++){
		// 		ans = gcd(ans, v[L]-v[K]);
		// 	}
		// }

		for(int K = 0; K < (int)v.size(); K++) ans = gcd(ans, v[K]);

		if(a < b) swap(a, b);
		// cout << a << ' ' << b << ' ' << a-b << "\n";

		// sort(v.begin(), v.end());
		// cout << v << "\n";

		// if(calc(a-b)) cout << "YES\n";
		// else cout << "NO\n";

		if(ans && (a-b)%ans==0) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}





























