
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
int ara[N+5];
bool valid(int j, int n)
{
	//cout << j << ' ';
	int pre = -1, g;
	for(int K = 0; K < n-1; K++){
		if(K+1 == j && K+2 < n) g = gcd(ara[K], ara[K+2]);
		else if(K+1 == j && K+2 >= n) continue;
		else if(K == j) continue;
		else g = gcd(ara[K], ara[K+1]);
		
		if(g >= pre) {}
		else return 0;
		
		pre = g;
	}
	
	return true;
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
        for(int K = 0; K < n; K++) cin >> ara[K];
        
        vector<int> v;
        for(int K = 0; K < n-1; K++) v.push_back(gcd(ara[K], ara[K+1]));
        
        bool f = 0;
        bool ok = 0;
        for(int K = 0; K < n-2; K++){
			if(f){
				if(v[K] > v[K+1]){
					ok = 0;
					//cout << "loss " << K << "\n";
					break;
				}
				continue;
			}
			
			if(v[K] > v[K+1]){
				//cout << K << ' ';
				for(int L = K; L < min(n, K+3); L++){
					if(valid(L, n)){
						ok = 1;
						//cout << L << ' ';
						K = L;
						break;
					}
				}
				//cout << "ok" << "\n";
				
				f = 1;
			}
		}
		
		if(!f){
			ok = 1;
			int pre = -1, g;
			for(int K = 0; K < n-1; K++){
				g = gcd(ara[K], ara[K+1]);
				if(pre > g) {
					ok = 0;
					break;
				}
			}
		}
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
    }

    return 0;
}





























