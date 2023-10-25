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
		ll n; cin >> n;
		ll ara[n];
		for(int K = 0; K < n; K++) cin >> ara[K];

		ll q; cin >> q;

		if(q == 0){
			for(int K = 0; K < n;K++) cout << ara[K] << ' ';
			cout << "\n";
			continue;
		}


		ll cc[q+1][3];
		for(int K = 0; K < q; K++){
			cin >> cc[K][0] >> cc[K][1] >> cc[K][2];
			cc[K][0]--;
		}

		// cout << n << '\n';
		// for(int K = 0; K <n; K++) cout << ara[K] << ' ';
		// 	cout << "\n";
		// cout << q << "\n";
		// for(int K = 0; K < q; K++){
		// 	for(int L = 0; L < 3; L++) cout << cc[K][L] << ' ';
		// 		cout << "\n";

		// }
		// cout << "\n";

		ll b[n];
		for(int K = 0; K < n; K++) b[K] = 0;

		set<ll> ss;

		// int q; cin >> q;
		ll ans = 0;
		for(int K = 0; K < q; K++){
			ll l = cc[K][0], r = cc[K][1], x = cc[K][2];

			// cout << K << ' ' << l << ' ' << r << ' ' << x << "\n";

			b[l] += x;
			if(r < n) b[r] -= x;

			ss.insert(l);
			if(r < n) ss.insert(r);

			if(b[l] == 0) ss.erase(l);
			if(r < n && b[r] == 0) ss.erase(r);

			ll val = *ss.begin();

			// cout << K << ' ' << c[K][2] << ' ' << val << "\n";

			if(b[val] <= 0){
				ans = K+1;
				for(auto it: ss) b[it] = 0;
				ss.clear();
			}
		}

		memset(b, 0ll, sizeof b);
		for(int K = 0; K < ans; K++){
			b[cc[K][0]] += cc[K][2];
			if(cc[K][1] < n) b[cc[K][1]] -= cc[K][2];
		}

		for(int K = 1; K < n; K++) b[K] += b[K-1];

		for(int K = 0; K < n; K++) cout << ara[K] + b[K] << ' ';
		cout << "\n";
	}
	
	return 0;
}





































