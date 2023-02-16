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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
struct ordered_multiset { // multiset supporting duplicating values in set
	ll len = 0;
	const ll ADD = 1000010;
	const ll MAXVAL = 1000000010;
	unordered_map<ll, ll> mp; // hash = 96814
	tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> T;

	ordered_multiset() { len = 0; T.clear(), mp.clear(); }

	inline void insert(ll x){
		len++, x += MAXVAL;
		ll c = mp[x]++;
		T.insert((x * ADD) + c); }

	inline void erase(ll x){
		x += MAXVAL;
		ll c = mp[x];
		if(c) {
			c--, mp[x]--, len--;
			T.erase((x*ADD) + c); } }

	inline ll kth(ll k){        // 1-based index,  returns the
		if(k<1 || k>len) return -1;     // K'th element in the treap,
		auto it = T.find_by_order(--k); // -1 if none exists
		return ((*it)/ADD) - MAXVAL; } 

	inline ll lower_bound(ll x){      // Count of value <x in treap
		x += MAXVAL;
		ll c = 0;//mp[x];
		return (T.order_of_key((x*ADD)+c)); } 

	inline ll upper_bound(ll x){      // Count of value <=x in treap
		x += MAXVAL;
		ll c = mp[x];
		return (T.order_of_key((x*ADD)+c)); }

	inline ll size() { return len; }   // Number of elements in treap
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	int n; cin >> n;
	
	vector<pair<int, int> > ara, v;
	ordered_multiset ss;
	map<pair<int, int>, int> mp;
	
	for(int K = 0; K < n; K++) {
		int a, b;
		cin >> a >> b;
		
		ara.push_back({a, b});
		v.push_back({a, b});
		//v2.push_back({b, a});
		ss.insert(b);
	}
	
	sort(v.begin(), v.end());
	
	//for(int K = 0; K < n; K++) ss.insert({{v[K].second, v[K].first}, K});
	
	for(int K = 0; K < n; K++){
		int ans = ss.upper_bound(v[K].second)-1;
		
		//cout << ans << "\n";
		mp[v[K]] = ans;
		
		ss.erase(v[K].second);
	}
	
	for(auto it:ara) cout << mp[it] << "\n";
	
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
