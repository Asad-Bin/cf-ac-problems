
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



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1; 
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        // cout << "Case " << cs << ": ";
        
        int n, k; cin >> n >> k;
        string s; cin >> s;
        
        if(n/k == 1){
			int z = 0, o = 0;
			for(int L = 0; L < k; L++){
				if(s[L] == '0') z++;
				else o++;
			}
			
			if(o && z) cout << -1 << "\n";
			else cout << k << "\n";
			
			continue;
		}
        
        bool f = 1;
        int i = -1;
        if(s[n-1] == '0') f = 0;
        for(int K = n-1; K >= k-1; K-=k){
			i = K-k;
			int z = 0, o = 0;
			for(int L = 0; L < k; L++){
				if(s[K-L] == '0') z++;
				else o++;
			}
			
			if(!f && z == k){
				f ^= 1;
				continue;
			}
			if(f && o == k){
				f ^= 1;
				continue;
			}
			
			if(K == n-1){
				if(f && o != k) K += z;
				if(!f && z != k) K += o;
			}
			else if(f && o != k){
				i = K;
				break;
			}
			else if(!f && z != k){
				i = K;
				break;
			}
			
			f ^= 1;
		}
		
		if(i == -1) {
			int x = n/k;
			
			//if((x&1) && )
			
			if(!(x&1) || x == 1) cout << k << "\n";
			else cout << 2*k << "\n";
			
			continue;
		}
		//cout << "hi\n";
		
		string str = s.substr(0, i+1);
		//cout << str << "\n";
		reverse(str.begin(), str.end());
		
		str = s.substr(i+1, n-1-i) + str;
		//cout << str << "\n";
		
		//if(i != -1) cout << i+1 << "\n";
		//else{
			//cout << -1 << "\n";
		//}
		
		bool ok = 1;
		f = 1;
		if(str[0] == '0') f = 0;
		for(int K = 0; K <= n-k; K+=k){
			int o = 0, z = 0;
			for(int L = 0; L < k; L++){
				if(str[K+L] == '0') z++;
				else o++;
			}
			
			if(f && o == k) {}
			else if(!f && z == k) {}
			else{
				ok = 0;
				break;
			}
			
			f ^= 1;
		}
		
		if(!ok) cout << -1 << "\n";
		else cout << i+1 << "\n";
    }

    return 0;
}





























