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


const int N = 3e5;
int tin[N+5], low[N+5];
bool vis[N+5];
vector<int> edge[N+5], ara[N+5];
map<pair<int, int>, int> art_bridge;

int timer = 0;
void dfs(int u, int p = -1){
	tin[u] = low[u] = timer++;
	vis[u] = 1;
	
	for(int to : edge[u]){
		if(to == p) continue;
		
		if(vis[to]){
			low[u] = min(low[u], tin[to]);
		}
		else{
			dfs(to, u);
			
			low[u] = min(low[u], low[to]);
			//cout << u << ' ' << low[u] << ' ' << tin[u] << "\n";
			if(low[to] > tin[u]){
				art_bridge[{u, to}] = art_bridge[{to, u}] = 1;
			}
		}
	}
}
void cut_bridge(int n)
{
	timer = 0;
	art_bridge.clear();
	for(int K = 1; K <= n; K++) vis[K] = 0;
	
	for(int K = 1; K <= n; K++){
		if(!vis[K]){
			dfs(K);
			//cout << K << ' ';
		}
	}
	//cout << "\n";
}

//int color[N+5];
//void dfs2(int u, int p, int col){
	//vis[u] = 1;
	//color[u] = col;
	
	//for(int to : edge[u]){
		//if(!vis[to] && art_bridge.find({u, to}) == art_bridge.end()){
			//dfs2(to, u, col);
		//}
	//}
//}

map<pair<int, int>, int> mp;
void dfs2(int u, int p)
{
	vis[u] = 1;
	for(int to : edge[u]){
		if(to != p){
			if(mp.find({to, u}) == mp.end()) mp[{u, to}] = 1;
			
			if(vis[to]) continue;
			
			dfs2(to, u);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m; cin >> n >> m;
	
	for(int K = 0; K < m; K++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	cut_bridge(n);
	//for(auto it: art_bridge) cout << it.first.first << ' ' << it.first.second << "\n";
	
	if((int)art_bridge.size()){
		cout << 0 << "\n";
		return 0;
	}
	
	memset(vis, 0, sizeof vis);
	dfs2(1, 1);
	
	for(auto it: mp) cout << it.first.first << ' ' << it.first.second << "\n";
	
	//memset(vis, 0, sizeof vis);
	//int i = 1;
	//for(int K = 1; K <= n; K++){
		//if(!vis[K]) dfs2(K, -1, i++);
	//}
	////for(int K = 1; K <= n; K++) cout << color[K] << ' ' ;
	////cout << "\n";
	
	//map<pair<int, int>, int> mp;
	//for(auto it : art_bridge){
		//mp[{color[it.first.first], color[it.first.second]}] = mp[{color[it.first.second], color[it.first.first]}] = 1;
		
	//}
	
	////for(auto it: art_bridge) cout << it.first.first << ' ' << it.first.second << "\n";
	////for(auto it: mp) cout << it.first.first << ' ' << it.first.second << "\n";
	
	//for(auto it: mp) {
		//ara[it.first.first].push_back(it.first.second);
		//ara[it.first.second].push_back(it.first.first);
	//}
	
	//n = i-1;
	//queue<int> q;
	//q.push(1);
	//vector<int> dist(n+1, -1);
	//dist[1] = 0;
	
	//while(!q.empty()){
		//int u = q.front();
		//q.pop();
		
		//for(int to : ara[u]){
			//if(dist[to] == -1){
				//dist[to] = dist[u] + 1;
				//q.push(to);
			//}
		//}
	//}
	//int node = 1;
	//for(int K = 1; K <= n; K++) if(dist[K] > dist[node]) node = K;
	
	//while(!q.empty()) q.pop();
	
	//q.push(node);
	//dist.assign(n+1, -1);
	//dist[node] = 0;
	
	//while(!q.empty()){
		//int u = q.front();
		//q.pop();
		
		//for(int to : ara[u]){
			//if(dist[to] == -1){
				//dist[to] = dist[u] + 1;
				//q.push(to);
			//}
		//}
	//}
	
	//node = 1;
	//for(int K = 1; K <= n; K++) if(dist[K] > dist[node]) node = K;
	
	//cout << dist[node] << "\n";
	
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
