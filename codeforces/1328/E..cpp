/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


const int MX = 2e5;
vector<int> ara[MX+5];
int query[MX+5], level[MX+5], in_time[MX+5], out_time[MX+5], parent[MX+5];
int tim = 0;

void dfs(int u, int p, int d)
{
	level[u] = d;
	in_time[u] = tim++;
	parent[u] = p;
	
	for(auto to:ara[u]){
		if(to != p){
			dfs(to, u, d+1);
		}
	}
	
	out_time[u] = tim++;
}
bool test(int a, int b)
{
	return in_time[a] <= in_time[b] && out_time[a] >= out_time[b];
}
int main()
{
	int n, m, u, v, k;
	
	cin >> n >> m;
    
	for(int K = 1; K < n; K++){
		cin >> u >> v;
		ara[u].push_back(v);
		ara[v].push_back(u);
	}
	
	dfs(1, -1, 0);
	
	while(m--){
		cin >> k;
		
		for(int K = 0; K < k; K++) cin >> query[K];
		
		u = level[1];
		for(int K = 0; K < k; K++) if(level[u] < level[query[K]]) u = query[K];
		
		for(int K = 0; K < k; K++) if(query[K] != 1) query[K] = parent[query[K]];
		
		bool ok = 1;
		for(int K = 0; K < k; K++) ok &= test(query[K], u);
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
