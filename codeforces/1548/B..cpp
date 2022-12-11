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

ll gcd(ll a, ll b){ if(!a) swap(a, b); while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}
ll bigmod(ll a,ll b,ll mod){ if(b==0){ return 1;} ll tm=bigmod(a,b/2,mod); tm=(tm*tm)%mod; if(b%2==1) tm=(tm*a)%mod; return tm;}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}



const int lg = 20;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll t; cin >> t;
	while(t--){
		ll n; cin >> n; 
		
		ll ara[n];
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		for(int K = n-1; K >= 1; K--) ara[K] = abs(ara[K] - ara[K-1]);
		
		//for(int K = 1; K < n; K++) cout << ara[K] << ' ';
		//cout << "\n";
		
		if(n == 1){
			cout << 1 << "\n";
			continue;
		}
		if(n == 2){
			if(ara[1] == 1) cout << 1 << "\n";
			else cout << 2 << "\n";
			continue;
		}
		
		ll spt[lg+1][n];
		//memset(spt, 1ll, sizeof spt);
		//for(int K = 0; K < lg; K++)
			//for(int L = 0; L < n; L++) spt[K][L] = 1;
		
		for(int K = 1; K < n; K++) {
			spt[0][K] = ara[K];
			//else spt[0][K] = ;
		}
		for(ll K = 1; K < lg; K++){
			for(ll  L = 1; K < n; L++){
				if(L+(1ll<<K)-1 >= n) break;
				spt[K][L] = gcd(spt[K-1][L], spt[K-1][L+(1<<(K-1))]);
			}
		}
		for(ll K = 1; K < n; K++){
			for(ll L = 0; L < lg; L++){
				if(K+(1ll<<L)-1 >= n) break;
				//cout << spt[L][K] << ' ';
			}
			//cout <<  "\n";
		}
		
		ll ans = 0;
		for(ll K = 1; K < n; K++){
			ll i = K;
			ll g = -1;
			for(ll L = lg-1; L >= 0; L--){
				if(i+(1ll<<L)-1 < n && ((g == -1 && spt[L][i] > 1) || spt[L][i] == 0 || (g > -1 && gcd(g, spt[L][i]) > 1))){
					if(g <= 0) g = spt[L][i];
					else if(spt[L][i] == 0) {}
					else g = gcd(g, spt[L][i]);
					i += (1ll<<L);
				}
			}
			if(g != 1) ans = max(ans, i-K);
			//debug(K) debug(i) debug(ans)
		}
		
		//ll g = ara[1], cnt = 1, ans = 1;
		//for(int K = 2; K < n; K++){
			//if(ara[K] == 0){
				//cnt++;
				//ans = max(ans, cnt);
				//continue;
			//}
			
			//g = gcd(g, ara[K]);
			
			//if(g > 1){
				//cnt++;
			//}
			//else{
				//cnt = 1;
				//g = ara[K];
			//}
			
			//ans = max(ans, cnt);
		//}
		
		cout << ans+1 << "\n";
	}
	
	return 0;
}





































