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
vector<int> ara[N+5];
int dist = 0, a, b, mx = 0;
vector<int> vec;

// bool dfs(int at, int p, int h)
// {
// 	// v.push_back(at);

// 	if(at == b){
// 		dist = h;
// 		return true;
// 	}

// 	bool ok = 0;
// 	for(auto it: ara[at]){
// 		if(it != p){
// 			v.push_back(it);
// 			ok |= dfs(it, at, h+1);
// 			if(ok) return true;
// 			v.pop_back();
// 		}
// 	}
// 	return false;
// }
// int dfs2(int at, int p, int h)
// {
// 	// v.push_back(at);

// 	if((int)ara[at].size() == 1){
// 		dist = max(dist, h);
// 	}

// 	int ans = 0;
// 	for(auto it: ara[at]){
// 		if(it != p){
// 			ans += 1 + dfs2(it, at, h+1);
// 		}
// 	}
// 	return ans+1;
// }
void dis2(int source, int n)
{
	queue<int> Q;
    vector<int> level(n+1, -1), pre(n+1, -1);
    int ans = 0;
    int u, v;
    Q.push(source);
    level[source] = 0;
    while (!Q.empty()) {
            u = Q.front();
            Q.pop();
            for (int K = 0; K < ara[u].size(); K++) {
                    v = ara[u][K];
              if (level[v] == -1) {
                    level[v] = level[u] + 1;
                    pre[v] = u;

                    if(v == b){
                    	while(!Q.empty()) Q.pop();
                    	break;
                    }
                    // ans = max(ans, level[v]);
                    Q.push(v);
                    // can be matched with destination here to get the distance.
                    // Or, can be calculated new persons or nodes    comes in
                    // consideration for the first time.
             }
            }
    }
    // return ans;
    int i = b;
    vec.push_back(i);
    while(i != a){
    	i = pre[i];
    	vec.push_back(i);
    	if(i == a) break;
    }
}
int dis(int source, int n)
{
	queue<int> Q;
    vector<int> level(n+1, -1);
    int ans = 0;
    int u, v;
    Q.push(source);
    level[source] = 0;
    while (!Q.empty()) {
            u = Q.front();
            Q.pop();
            for (int K = 0; K < ara[u].size(); K++) {
                    v = ara[u][K];
              if (level[v] == -1) {
                    level[v] = level[u] + 1;
                    ans = max(ans, level[v]);
                    Q.push(v);
                    // can be matched with destination here to get the distance.
                    // Or, can be calculated new persons or nodes    comes in
                    // consideration for the first time.
             }
            }
    }
    return ans;
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
		cin >> a >> b;

		for(int K = 1; K <= n; K++) ara[K].clear();
		for(int K = 1; K < n; K++){
			int u, v; cin >> u >> v;
			ara[u].push_back(v);
			ara[v].push_back(u);
		}

		dist = 0;
		vec.clear();
		// v.push_back(a);
		dis2(a, n);

		int i = vec[((int)vec.size()+2)/2 - 1];

		dist = 0;
		// int ans = dfs2(i, i, 0)-1;
		int ans = (n-1)*2;
		// cout << i << ' ' << ans << ' ' << dis(i, n) << ' ' << (vec.size()+1)/2-1 << "\n";
		ans -= dis(i, n);		
		ans += ((int)vec.size())/2;

		// cout << "i = " << i << "\n";

		cout << ans << "\n";
	}

	return 0;
}





























