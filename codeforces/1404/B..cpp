/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


const int MX = 1e5;
int tim = 0;
//int in_time[MX+5], out_time[MX+5], 
int d[MX+5];
vector<int> ara[MX+5];

void dfs(int u, int p, int dep)
{
	//in_time[u] = tim++;
	d[u] = dep;
	
	for(int K = 0; K < (int)ara[u].size(); K++){
		if(ara[u][K] != p){
			dfs(ara[u][K], u, dep+1);
		}
	}
	
	//out_time[u] = tim++;
}
int tree_dia;
void dfs2(int u, int p, int dep)
{
	tree_dia = max(tree_dia, dep);
	
	for(int K = 0; K < (int)ara[u].size(); K++){
		if(ara[u][K] != p){
			dfs2(ara[u][K], u, dep+1);
		}
	}
}

int main()
{
	int t, n, a, b, da, db, u, v;
	
	cin >> t;
	while(t--){
		cin >> n >> a >> b >> da >> db;
		
		for(int K = 1; K <= n; K++) ara[K].clear();
		for(int K = 1; K < n; K++){
			cin >> u >> v;
			
			ara[u].push_back(v);
			ara[v].push_back(u);
		}
		
		dfs(b, -1, 0);
		int b_mx = 0, b_nod = -1;
		for(int K = 1; K <= n; K++){
			//if(in_time[a] <= in_time[K] && out_time[K] <= out_time[a]){
				//if(d[K] > mx){
					//mx = d[K];
					//nod = K;
				//}
			//}
			//else if(in_time[a] > in_time[K] && out_time[K] > out_time[a]){
				//;
			//}
			//else{
				if(d[K] > b_mx){
					b_mx = d[K];
					b_nod = K;
				}
			//}
		}
		
		//cout << "node = " << b_nod << "\n";
		tree_dia = 0;
		dfs2(b_nod, -1, 0);
		
		//cout << tree_dia << "\n";
		if(db <= 2*da || d[a] <= da || 2*da >= tree_dia){
			cout << "Alice\n";
			continue;
		}
		
		
			cout << "Bob\n";
	}
	
	return 0;
}
