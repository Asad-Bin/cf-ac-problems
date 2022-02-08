/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


const int MX = 1e3;
vector<int> ara[MX+5];
bool mark[MX+5], vis[MX+5];

//pair<int, int> bfs(int s)
//{
	//queue<int> q;
	//q.push(s);
	//vis[s] = 1;
	
	//int edge = 0, node = 0;
	//while(!q.empty()){
		//int u = q.front();
		//q.pop();
		//node++;
		
		//for(int K = 0; K < n; K++){
			//if(!vis[ara[u][K]]){
				//q.push(ara[u][K]);
				//vis[ara[u][K]] = 1;
				//edge++;
			//}
		//}
	//}
	
	//return {node, edge};
//}
int i;
vector<pair<int, int> > v[MX+5];
vector<int> nod[MX+5];
map<pair<int, int>, int> mp;
void dfs(int u, int p)
{
	vis[u] = 1;
	mark[u] = 1;
	nod[i].push_back(u);
	
	for(int K = 0; K < (int)ara[u].size(); K++){
		if(ara[u][K] != p && vis[ara[u][K]] && !mp[{min(u, ara[u][K]), max(u, ara[u][K])}]){
			v[i].push_back({min(u, ara[u][K]), max(u, ara[u][K])});
			mp[{min(u, ara[u][K]), max(u, ara[u][K])}] = true;
		}
		
		if(!vis[ara[u][K]] && ara[u][K] != p){
			dfs(ara[u][K], u);
		}
	}
}
struct xxx{
	int a, b, c, d;
	
	xxx(int _a, int _b, int _c, int _d){
		a = _a;
		b = _b;
		c = _c;
		d = _d;
	}
};
vector<xxx> sol;
int main()
{
	int n, a, b;
	i = 0;
	
	cin >> n;
	
	for(int K = 1; K < n; K++){
		cin >> a >> b;
		ara[a].push_back(b);
		ara[b].push_back(a);
	}
	
	for(int K = 1; K <= n; K++){
		if(!mark[K]){
			i++;
			memset(vis, 0, sizeof vis);
			
			dfs(K, -1);
		}
	}
	
	vector<pair<int, int> > edge;
	vector<int> wait;
	
	for(int L = 0; L < (int)v[1].size(); L++) edge.push_back(v[1][L]);
	for(int K = 2; K <= i; K++){
		if(!v[K].empty()){
			sol.push_back(xxx(v[K][0].first, v[K][0].second, nod[1][0], v[K][0].first));
			
			for(int L = 1; L < (int)v[K].size(); L++) edge.push_back(v[K][L]);
			
			v[K].clear();
			nod[K].clear();
		}
		else if(!edge.empty()){
			sol.push_back(xxx(edge.back().first, edge.back().second, edge.back().first, nod[K][0]));
			
			edge.pop_back();
			
			v[K].clear();
			nod[K].clear();
		}
		else{
			wait.push_back(K);
		}
	}
	
	for(auto it:wait){
		sol.push_back(xxx(edge.back().first, edge.back().second, edge.back().first, nod[it][0]));
		
		edge.pop_back();
		
		v[it].clear();
		nod[it].clear();
	}
	
	cout << (int)sol.size() << "\n";
	for(auto it:sol) cout << it.a << ' ' << it.b << ' ' << it.c << ' ' << it.d << "\n";
	
	return 0;
}
