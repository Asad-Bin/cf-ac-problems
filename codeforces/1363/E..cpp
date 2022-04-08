/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


const int MX = 2e5;
int ara[MX+5][3];
vector<int> edge[MX+5];

long long ans = 0;

pair<int, int> add(pair<int, int> a, pair<int, int> b)
{
	return make_pair(a.first+b.first, a.second+b.second);
}
pair<int, int> dfs(int u, int p, int mn)
{
	pair<int, int> r;
	if(ara[u][1] == ara[u][2]) r = make_pair(0, 0);
	else r = (ara[u][1]==0 ? make_pair(0, 1) : make_pair(1, 0));
	
	mn = min(mn, ara[u][0]);
	
	for(int K = 0; K < (int)edge[u].size(); K++){
		if(edge[u][K] != p){
			r = add(r, dfs(edge[u][K], u, mn));
		}
	}
	
	int mid = min(r.first, r.second);
	ans += (long long)mn*mid*2;
	//cout << u << ' ' << mn << ' ' << mid*2 << ' ' << ans << "\n";
	
	return make_pair(r.first-mid, r.second-mid);
}
int main()
{
	int n, u, v;
	
	cin >> n;
	
	for(int K = 1; K <= n; K++) cin >> ara[K][0] >> ara[K][1] >> ara[K][2];
	
	for(int K = 1; K <= n; K++) edge[K].clear();
	for(int K = 0; K < n-1; K++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	pair<int, int> r = dfs(1, 1, 1e9+7);
	
	if(r != make_pair(0, 0)){
		cout << "-1\n";
		return 0;
	}
	
	cout << ans << "\n";
	
	return 0;
}
