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
int ara[N+5];
vector<int> col[N+5];
int dp[N+5][2];
int n;
int calc(int at, int pre)
{
	if(at >= n) return 0;
	
	if(dp[at][pre] != -1) return dp[at][pre];
	
	int ans = 0;
	auto it = upper_bound(col[ara[at]].begin(), col[ara[at]].end(), at) - col[ara[at]].begin();
	
	//if(it < (int)col[ara[at]].size()) cout << at << ' ' << col[ara[at]][it] << ' ' << pre << "\n";
	if(it < (int)col[ara[at]].size() && col[ara[at]][it] > at) ans = max(ans, calc(col[ara[at]][it], 0) + col[ara[at]][it]-at+pre);
	//for(int K = (int)col[ara[at]].size()-1; K > at; K--){
		//if(col[ara[at]][K] <= at) break;
		
		//ans = max(ans, calc(col[ara[at]][K], 1) + col[ara[at]][K]-at+pre);
	//}
	
	ans = max(ans, calc(at+1, 1));
	
	//cout << at << ' ' << ans << "\n";
	return dp[at][pre] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--){
		cin >> n;
		
		for(int K = 1; K <= n; K++) col[K].clear();
		for(int K = 1; K <= n; K++) {
			cin >> ara[K];
			col[ara[K]].push_back(K);
			
		}
		//vector<pair<int, int>> v;
		//for(int K = 1; K <= n; K++){
			//for(int L = 1; L < (int)col[K].size(); L++){
				//v.push_back({col[K][L-1], col[K][L]});
			//}
		//}
		
		//sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int,int> b){
			//return a.second < b.second;
		//});
		
		//for(auto [i, j]: v) cout << i << ' ' << j << "\n";
		
		//int l = v[0].first, r = v[0].second;
		//int ans = 0;
		//for(int K = 1; K < (int)v.size(); K++){
			//if(v[K].second-v[K].first > r-l){
				//l = v[K].first;
				//r = v[K].second;
			//}
			//else if(v[K].first > r){
				//ans += r-l+(r != v[K].first);
				//l = v[K].first;
				//r = v[K].second;
			//}
		//}
		//ans += r-l+1;
		
		//vector<pair<int, int> > v;
		//for(int K = 1; K <= n; K++){
			//if(col[K].size() >= 2){
				//v.push_back({col[K][0], col[K].back()});
			//}
		//}
		
		//sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b){
			//return a.second-a.first > b.second-b.first;
		//});
		
		//int l = -1, r = -1, ans = 0;
		//for(int K = 0; K < (int)v.size(); K++){
			//if(v[K].second >= l || v[K].first <= r) continue;
			
			//ans += v[K].second-v[K].first+1;
			//l = min(l, v[K].first);
			//r = max(r, v[K].second);
		//}
		
		for(int K = 1; K <= n; K++) dp[K][0] = dp[K][1] = -1;
		cout << calc(1, 1) << "\n";
	}
	
	return 0;
}





































