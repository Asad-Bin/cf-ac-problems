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


const int N = 2e5;
int idx[N+5];
vector<int> srt;
string s;

int tree[4*N+5];
void build(int at, int l, int r)
{
	if(l == r){
		tree[at] = s[srt[l-1]] - '0';
		return;
	}
	
	int mid = (l + r)/2;
	
	build(at*2, l, mid);
	build(at*2+1, mid+1, r);
	
	tree[at] = tree[at*2] + tree[at*2+1];
}
void update(int at, int l, int r, int i)
{
	if(l == r){
		if(s[srt[i-1]] == '0') s[srt[i-1]] = '1';
		else s[srt[i-1]] = '0';
		
		tree[at] = (s[srt[l-1]] - '0');
		return;
	}
	
	int mid = (l + r)/2;
	
	if(i <= mid) update(at*2, l, mid, i);
	else update(at*2+1, mid+1, r, i);
	
	tree[at] = tree[at*2] + tree[at*2+1];
}
int query(int at, int l, int r, int L, int R)
{
	if(r < L || R < l) return 0;
	if(L <= l && r <= R) return tree[at];
	
	int mid = (l + r)/2;
	
	int ans = query(at*2, l, mid, L, R);
	ans += query(at*2+1, mid+1, r, L, R);
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, q ;cin >> n >> m >> q;
	
	cin >> s;
	
	set<int> ss; 
	for(int K = 0; K < n; K++) ss.insert(K);
	for(int K = 0; K < m; K++){
		int a, b; cin >> a >> b; a--; b--;
		
		vector<int> v;
		auto it = ss.lower_bound(a);
		while(it != ss.end() && (*it) <= b){
			v.push_back(*it);
			++it;
		}
		
		for(auto val: v) {
			ss.erase(val);
			srt.push_back(val);
		}
	}
	
	int last = (int)srt.size();
	for(auto it: ss) srt.push_back(it);
	//for(auto it: srt)  cout << it+1 << ' ';
	//cout << "\n";
	
	for(int K = 0; K < n; K++) idx[srt[K]] = K;
	build(1, 1, n);
	
	while(q--){
		int x; cin >> x; x--;
		
		update(1, 1, n, idx[x]+1);
		
		int ones = min(last, tree[1]);
		int ans = query(1, 1, n, 1, min(ones, last));
		
		cout << ones-ans << "\n";
	}
	
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
