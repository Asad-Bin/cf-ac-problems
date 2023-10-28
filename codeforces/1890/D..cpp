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
		ll n, c; cin >> n >> c;
		
		ll ara[n+1];
		for(int K = 1; K <= n; K++) cin >> ara[K];
		
		//ll  sum = ara[1];
		
		//map<ll, set<ll> > mp;
		////for(ll K = 2; K <= n; K++){
			//mp[ara[K]].insert(K);
		//}
		
		bool ok = 1;
		//ll cnt = 1;
		//while(cnt < n && !mp.empty()){
			//while(!mp.empty() && mp.rbegin()->second.empty()){
				//mp.erase(mp.rbegin()->first);
			//}
			//if(mp.empty()) break;
			
			//ll i = mp.rbegin()->first;
			//ll j = *mp.rbegin()->second.begin();
			//if(i + sum >= j*c){
				//sum += i;
				//mp.rbegin()->second.erase(j);
				
				//if(mp.rbegin()->second.empty()){
					//mp.erase(mp.rbegin()->first);
				//}
			//}
			//else{
				//ok = 0;
				//break;
			//}
			
			//cnt++;
		//}
		
		vector<pair<ll, ll> > v;
		for(int K = 2; K <= n; K++) v.push_back({K, ara[K]});
		
		sort(v.begin(), v.end(), [&](pair<ll, ll> a, pair<ll, ll> b){
			//if(a.second == b.second) a.first > b.first;
			//return a.second < b.second;
			//if(a.first == b.first) return a.second < b.second;
			//return a.first > b.first;
			return c*a.first-a.second < c*b.first-b.second;
		});
		
		ll sum = ara[1];
		for(int K = 0; K < n-1; K++){
			sum += v[K].second;
			
			if(sum < v[K].first*c){
				ok = 0;
				break;
			}
		}
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}





































