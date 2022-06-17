// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 2e5;

vector<int> ara[MX+5];

ll dist[MX+5];
int n;

priority_queue<pair<int, int> > PQ;
map<int, ll> mp;

ll dijkstra(int s, int d, int m)
{
	fill(dist, dist+n+1, m);
	
	dist[d] = 0;
	PQ.push({0, d});
	
	bool mark[n+5] = {0};
	
	while(!PQ.empty()){
		int u = PQ.top().second;
		PQ.pop();
		
		if(mark[u]) continue;
		mark[u] = 1;
		
		for(int v:ara[u]){
			if(dist[v] > mp[v]+dist[u]){
				dist[v] = mp[v] + dist[u];
				PQ.push({-dist[v], v});
			}
			mp[v]--;
		}
	}
	
	return dist[s];
}
int main()
{
	int t, m, a, b;
	
	t = 1;
	while(t--){
		scanf("%d%d", &n, &m);
		
		for(ll K = 1; K <= n; K++) ara[K].clear();
		
		for(ll K = 0; K < m; K++){
			scanf("%d%d", &a, &b);
			
			ara[b].push_back(a);
			mp[a]++;
		}
		
		ll ans = dijkstra(1, n, m);
		
		printf("%lld\n", ans);
	}
	
	return 0;
}




















































