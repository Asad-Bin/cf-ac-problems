/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


const int MX = 1e5;
const int MXI = 1e7+9;

long long ara[MX+5];
vector<int> edge[MX+5], dist(MX+5);
bool vis[MX+5];
int q[MX+5];
int ans = MXI+5;

void bfs(int s)
{
	fill(dist.begin(), dist.end(), MXI);
	
	int i = 0;
	q[i++] = s;
	dist[s] = 0;
	
	for(int K = 0; K < i; K++){
		int u = q[K];
		
		for(int L = 0; L < (int)edge[u].size(); L++){
			if(dist[edge[u][L]] == MXI){
				dist[edge[u][L]] = dist[u] + 1;
				q[i++] = edge[u][L];
			}
			else if(dist[u] <= dist[edge[u][L]]){
				ans = min(ans, dist[u]+dist[edge[u][L]]+1);
			}
		}
	}
}
int main()
{
	int n;
	vector<int> v;
	
	cin >> n;
	for(int K = 0; K < n; K++){
		cin >> ara[K];
		if(ara[K] == 0){
			K--;
			n--;
		}
	}
	
	for(int K = 0; K < 60; K++){
		for(int L = 0; L < n; L++){
			if(ara[L]&(1LL<<K)) v.push_back(L);
		}
		
		if((int)v.size() >= 3){
			cout << 3 << "\n";
			return 0;
		}
		v.clear();
	}
	
	for(int K = 0; K < n; K++){
		for(int L = 0; L < n; L++){
			if(K != L && (ara[K]&ara[L])!=0){
				edge[K].push_back(L);
			}
		}
	}
	
	for(int K = 0; K < n; K++){
		bfs(K);
	}
	
	if(ans >= MXI) cout << "-1\n";
	else cout << ans << "\n";
	
	return 0;
}












