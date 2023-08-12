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
		int n; cin >> n;
		int ara[n];
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		vector<int> b, c;
		bool ok = 1;
		
		sort(ara, ara+n);
		//for(int K = 0; K < n; K++){
			//ll x = ara[K];
			//vector<int> v;
			//for(ll L = 1; L*L <= x; L++){
				//if(x % L == 0){
					//v.push_back(L);
					//v.push_back(x/L);
				//}
			//}
			
			//bool f = 1;
			//for(auto it: v){
				//if(find(b.begin(), b.end(), it) != b.end()){
					////b.push_back(it);
					//f = 0;
				//}
				////else if(find(c.begin(), c.end(), it) == c.end())
				//else{
					////c.push_back(it);
				//}
				////else{
					////ok = 0;
				////}
			//}
			
			//if(f) b.push_back(ara[K]);
			//else c.push_back(ara[K]);
		//}
		
		//if(!ok || b.empty() || (c.empty() && (int)b.size() < 2)) cout << -1 << "\n";
		//else if(c.empty()){
			//cout << (int)b.size()-1 << ' ' << 1 << "\n";
			//for(int K = 0; K < (int)b.size()-2; K++) cout << b[K] << ' ';
			//cout << "\n";
			//cout << b.back() << "\n";
		//}
		//else{
			//cout << (int)b.size() << ' ' << (int)c.size() << "\n";
			//for(auto it: b) cout << it <<' ';
			//cout << "\n";
			//for(auto it: c) cout << it << ' ';
			//cout << "\n";
		//}
		
		b.push_back(ara[0]);
		for(int K = 1; K < n; K++){
			if(ara[K] == ara[K-1]){
				b.push_back(ara[K]);
			}
			else{
				for(int L = K; L < n; L++) c.push_back(ara[L]);
				break;
			}
		}
		
		if(b.empty() || c.empty()) cout << -1 << "\n";
		else{
			cout << (int)b.size() << ' ' << (int)c.size() << "\n";
			for(auto it: b) cout << it <<' ';
			cout << "\n";
			for(auto it: c) cout << it << ' ';
			cout << "\n";
		}
	}
	
	return 0;
}





































