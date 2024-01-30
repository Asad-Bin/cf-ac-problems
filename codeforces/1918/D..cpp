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



const ll N = 1e5;
ll ara[N+5], dp[N+5];
const ll inf = 1e15+7;

// int val = 0;
// int calc(int at)
// {
// 	int ans = 0;//calc(at+1)+ara[at];

// 	int sum = 0;
// 	for(int K = at; K < n; K++){
// 		ans = min(ans, calc(K+1)+ara[K]);

// 		sum += ara[K];
// 		if(sum > val) break;
// 	}

// 	return ans;
// }
ll tree[4*N+5];
void build(int at, int l, int r)
{
	tree[at] = inf;
	if(l == r){
		return;
	}

	int mid = (l + r)/2;

	build(at*2, l, mid);
	build(at*2+1, mid+1, r);

	// tree[at] = min(tree[at*2], tree[at*2+1]);
}
ll query(int at, int l, int r, int L, int R)
{
	if(R < L) return inf;
	if(r < L || R < l) return inf;
	if(L <= l && r <= R){
		return tree[at];
	}

	int mid = (l + r)/2;

	ll x = query(at*2, l, mid, L, R);
	ll y = query(at*2+1, mid+1, r, L, R);

	return min(x, y);
}
void update(int at, int l, int r, int idx, ll val)
{
	if(idx > r) return;
	if(l == r){
		tree[at] = val;
		return;
	}

	int mid = (l + r)/2;

	if(idx <= mid) update(at*2, l, mid, idx, val);
	else update(at*2+1, mid+1, r, idx, val);

	tree[at] = min(tree[at*2], tree[at*2+1]);
}
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
		ll l = 1, r = 0;
		for(int K = 0; K < n; K++){
			cin >> ara[K];
			l = max(l, ara[K]);
		}
		ara[n] = 0;

		for(int K = 1; K <= n; K++) ara[K] += ara[K-1];

		ll ans = inf; r = ara[n];

		while(l <= r){
			ll mid = (l + r)/2;

			// for(int K = 0; K < n; K++){
			// 	dp[K] = 0;
			// 	// update(1, 1, n, )
			// }
			// cout << l << ' ' << r << ' ' << mid << ":\n" ;
			// for(int K = 1; K <= n; K++) update(1, 1, n, K, inf);
			// build(1, 1, n);
			dp[0] = 0;

			for(int K = 0; K <= n; K++){
				auto it = lower_bound(ara, ara+n, (K ? ara[K-1] : 0)-mid)-ara;
				if((K ? ara[K-1] : 0)-(it ? ara[it-1] : 0) > mid) it++;

				// cout << K << ' ' <<(K ? ara[K-1] : 0)-mid << ' ' << it << ' ' << (it ? dp[it-1] : 0) << " ";

				ll mn = (it ? dp[it-1] : 0);
				if(it < K) mn = min(query(1, 1, n, it+1, K), mn);

				dp[K] = mn + ara[K]-(K ?  ara[K-1] : 0);
				update(1, 1, n, K+1, dp[K]);
				// cout << dp[K] << "\n";
			}
			// cout << dp[n] << "\n";

			if(dp[n] <= mid){
				ans = mid;
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}





























