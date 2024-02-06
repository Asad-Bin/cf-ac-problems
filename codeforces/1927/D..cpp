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



const int N = 2e5;
const int inf = 1e9+7;
int ara[N+5];
int tree[4*N+5][2];
map<int, vector<int> > lst;
void build(int at, int l, int r)
{
	if(l == r){
		tree[at][0] = tree[at][1] = ara[l];
		return;
	}
	int mid = (l + r)/2;

	build(at*2, l, mid);
	build(at*2+1, mid+1, r);

	tree[at][0] = min(tree[at*2][0], tree[at*2+1][0]);
	tree[at][1] = max(tree[at*2][1], tree[at*2+1][1]);
}

pair<int, int> query(int at, int l, int r, int L, int R)
{
	if(r < L || R < l) return {inf, 0};
	if(L <= l && r <= R) return {tree[at][0], tree[at][1]};

	int mid = (l + r)/2;

	pair<int, int> x = query(at*2, l, mid, L, R);
	pair<int, int> y = query(at*2+1, mid+1, r, L, R);

	return {min(x.first, y.first), max(x.second, y.second)};
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

		lst.clear();
		for(int K= 1; K <= n; K++){
			cin >> ara[K];
			lst[ara[K]].push_back(K);
		}

		build(1, 1, n);

		int q; cin >> q;
		while(q--){
			int l, r; cin >> l >> r;

			pair<int, int> x = query(1, 1, n, l, r);

			if(x.first == x.second) cout << -1 << ' ' << -1 << "\n";
			else{
				auto it = lower_bound(lst[x.first].begin(), lst[x.first].end(), l);
				cout << *it << ' ' ;
				auto it2 = lower_bound(lst[x.second].begin(), lst[x.second].end(), l);
				cout << *it2 << '\n' ;
			}
		}
		cout << "\n";
	}

	return 0;
}





























