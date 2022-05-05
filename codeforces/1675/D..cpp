// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int MX = 2e5;
vector<int> ara[MX+5], v;
vector<vector<int> > sol;
void dfs(int u, int p)
{
	v.push_back(u);
	if((int)ara[u].size() == 0){
		sol.push_back(v);
		v.clear();
		
		return;
	}
	
	dfs(ara[u][0], u);
	
	for(int K = 1; K < (int)ara[u].size(); K++){
		dfs(ara[u][K], u);
	}
}
int main()
{
	int t, n, x;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		for(int K = 1; K <= n; K++) ara[K].clear();
		sol.clear();
		int root = -1;
		for(int K = 1; K <= n; K++){
			cin >> x;
			
			if(x == K) root = x;
			else ara[x].push_back(K);
		}
		
		v.clear();
		dfs(root, root);
		
		cout << (int)sol.size() << "\n";
		for(auto arr:sol){
			cout << (int)arr.size() << "\n";
			for(auto it:arr) cout << it << ' ';
			cout << "\n";
		}
		cout << "\n";
	}
	
	return 0;
}




















































