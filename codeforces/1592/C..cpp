// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif

const int N = 1e5;
vector<int> ara[N+5], v(N+5);
int x;

int ans_h, ans_node;
int dfs(int u, int p, int h)
{
	int ans = v[u-1];
	
	for(int K = 0; K < (int)ara[u].size(); K++){
		if(ara[u][K] != p){
			ans ^= dfs(ara[u][K], u, h+1);
		}
	}
	
	if(ans == x && h > ans_h){
		ans_h = h;
		ans_node = u;
	}
	
	return ans;
}
int ans_node_1 = 0;
int dfs1(int u, int p, int h)
{
	int ans = v[u-1];
	
	for(int K = 0; K < (int)ara[u].size(); K++){
		if(ara[u][K] != p && ara[u][K] != ans_node){
			ans ^= dfs1(ara[u][K], u, h+1);
		}
	}
	
	if(ans == x){
		ans_node_1 = u;
	}
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	
	cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		
		x = 0;
		for(int K = 0; K < n; K++){
			cin>> v[K];
			x ^= v[K];
		}
		
		int a, b;
		for(int K = 1; K <= n; K++) ara[K].clear();
		for(int K = 1; K < n; K++){
			cin >> a >> b;
			ara[a].push_back(b);
			ara[b].push_back(a);
		}
		
		if(x == 0){
			cout << "YES\n";
			continue;
		}
		
		if(k == 2){
			cout << "NO\n";
			continue;
		}
		
		ans_h = ans_node = 0;
		dfs(1, 1, 0);
		
		//cout << "debug: " << ans_h << ' ' << ans_node << "\n";
		
		if(ans_node == 0){
			cout << "NO\n";
			continue;
		}
		
		ans_node_1 = 0;
		dfs1(1, 1, 0);
		
		if(ans_node_1) cout << "YES\n";
		else cout << "NO\n";
	}
	
	
	return 0;
}





































