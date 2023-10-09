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
	
	string ans = "";
	
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		ll x; cin >> x;
		
		int n = (int)s.length();
		
		set<pair<int, char> > ss1;
		set<pair<char, int> > ss2;
		set<int> ss;
		
		for(int K = 0; K < n-1; K++){
			//ss2.insert({s[K+1], K});
			if(s[K] > s[K+1]) ss1.insert({K, s[K+1]});
			ss.insert(K);
		}
		ss1.insert({n-1, '*'});
		ss.insert(n-1);
		
		while(x >= 0 && !ss1.empty()){
			//for(auto it: ss) cout << it <<      ' ';
			//cout << "\n";
			//for(auto it: ss1) cout << it.first << ' ' << it.second << "\n";
			//cout << x << "\n";
			
			int pos = ss1.begin()->first;
			char c = ss1.begin()->second;
			
			if(x <= (int)ss.size()){
				while((int)ss.size() >= x && x > 1){
					ss.erase(ss.begin());
					x--;
				}
				
				x = 0;
				ans += s[*ss.begin()];
				break;
			}
			
			x -= (int)ss.size();
			
			ss1.erase(ss1.begin());
			
			auto it = ss.find(pos);
			
			if(it == ss.begin()){
				//x -= (int)ss.size();
				ss.erase(it);
				
				continue;
			}
			
			--it;
			//auto it2 = ss1.find({*it, c});
			int i = *it;
			//if(it2 != ss1.end()) ss1.erase(it2);
			
			ss.erase(pos);
			
			if(s[i] > c) ss1.insert({i, c});
			
		}
			//for(auto it: ss) cout << it <<      ' ';
			//cout << "\n";
			//for(auto it: ss1) cout << it.first << ' ' << it.second << "\n";
			//cout << x << "\n";
			//cout << "\n";
	}
	
	cout << ans << "\n";
	
	return 0;
}





































