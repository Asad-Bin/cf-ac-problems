// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 2e5;
int p, i = 1;
vector<int> ara[MX+5], node(MX+5);
vector<pair<int, int> > v;
map<pair<int, int>, int> mp;
void dfs(int u, int f)
{
	for(int K = 0; K < (int)ara[u].size(); K++){
		if(ara[u][K] != f){
			if((node[u]&(1<<p))){
				node[ara[u][K]] = i;
				mp[{u, ara[u][K]}] = mp[{ara[u][K], u}] = i+(1<<p);
			}
			else{
				node[ara[u][K]] = i+(1<<p);
				mp[{u, ara[u][K]}] = mp[{ara[u][K], u}] = i;
			}
			i++;
			
			dfs(ara[u][K], u);
		}
	}
} 
int main()
{
	int t, n, a, b;
	
	cin >> t;
	while(t--){
		cin >> p;
		n = (1<<p);
		
		v.clear();
		mp.clear();
		for(int K = 1; K <= n; K++) ara[K].clear();
		for(int K = 1; K < n; K++){
			cin >> a >> b;
			ara[a].push_back(b);
			ara[b].push_back(a);
			v.push_back({a, b});
		}
		
		node[1] = n;
		i = 1;
		dfs(1, 1);
		
		cout << 1 << "\n";
		for(int K = 1; K <= n; K++) cout << node[K] << ' ';
		cout << "\n";
		for(int K = 0; K < (int)v.size(); K++) cout << mp[v[K]] << ' ';
		cout << "\n";
	}
	
	return 0;
}




















































