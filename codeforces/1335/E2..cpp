// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

//typedef long long ll;
//#ifndef ONLINE_JUDGE
//#define dbg_out cout
//#define debug(...) dbg_out << "DBG )> "; __f(#__VA_ARGS__, __VA_ARGS__);
//template<typename T1, typename T2> ostream& operator<<(ostream& out, pair<T1, T2> pr) { out << "{ " << pr.first << ", " << pr.second << " }"; return out; }
//template<typename T1> ostream& operator<<(ostream& out, vector<T1> vec) { out << "{ "; for (auto &x: vec) out << x << ", "; out << "}"; return out; }
//template<typename T1, size_t size> ostream& operator<<(ostream& out, array<T1, size> arr) { out << "{ "; for (auto &x: arr) out << x << ", "; out << "}"; return out; }
//template<typename T1, typename T2> ostream& operator<<(ostream& out, map<T1, T2> mp) { out << "{ ";for (auto &x: mp) out << x.first << ": " << x.second <<  ", "; out << "}"; return out; }
//template <typename Arg1> void __f(const char* name, Arg1&& arg1) { while (isspace(name[0])) name++; (isalpha(name[0]) || name[0] == '_') ? dbg_out << name << ": " << arg1 << "\n" : dbg_out << arg1 << "\n"; dbg_out.flush();}
//template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) { const char *comma = strchr(names + 1, ','); while (isspace(names[0])) names++; (isalpha(names[0]) || names[0] == '_') ? dbg_out.write(names, comma - names) << ": " << arg1 << " | " : dbg_out << arg1 << " | "; __f(comma + 1, args...);}
//#else
//#define debug(...)
//#endif

//ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
//ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
//ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}
//ll bigmod(ll a,ll b,ll mod){ if(b==0){ return 1;} ll tm=bigmod(a,b/2,mod); tm=(tm*tm)%mod; if(b%2==1) tm=(tm*a)%mod; return tm;}
//ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
//ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
//ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}



int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int ara[n+1];
		for(int K = 1; K <= n; K++) cin >> ara[K];
		
		int cnt[202][n+5];
		memset(cnt, 0, sizeof cnt);
		//int pos[202][n+5];
		//memset(pos, -1, sizeof pos);
		int mx[202];
		memset(mx, 0, sizeof mx);
		
		for(int K = 1; K <= n; K++){
			if(K) for(int L = 1; L <= 200; L++) cnt[L][K] = cnt[L][K-1];
			cnt[ara[K]][K]++;
			mx[ara[K]] = cnt[ara[K]][K];
			//pos[ara[K]][cnt[K][ara[K]]] = K;
		}
		
		//for(int K = 1; K <= 200; K++){
			//for(int L = 0; L < n; L++) cout << pos[K][L] << ' ';
			//cout << "\n";
		//}
		
		int ans = 1;
		for(int K = 1; K <= 200; K++){
			for(int L = 1; L <= n; L++){
				if(2*L > mx[K]) break;
				
				//int i = pos[K][L], j = pos[K][mx[K]-L+1];
				int i = lower_bound(cnt[K]+1, cnt[K]+n+1, L)-cnt[K];
				int j = lower_bound(cnt[K]+1, cnt[K]+n+1, mx[K]-L+1)-cnt[K];
				//debug(vector<int> {i, j});
				if(i == -1 || j <= 0 || i >= j) continue;
				
				int mid = 0;
				for(int M = 1; M <= 200; M++) mid= max(mid, cnt[M][j-1]-cnt[M][i]);
				//debug(vector<int>{K, L, i, j, mid});
				
				ans = max(ans, mid+L*2);
			}
		} 
		for(int K = 1; K <= 200; K++) ans = max(ans, cnt[K][n]);
		cout << ans << "\n";
	}
	
	return 0;
}





































