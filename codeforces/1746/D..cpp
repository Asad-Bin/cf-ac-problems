// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif


const int N = 2e5;
vector<ll> ara[N+5], s(N+5);
ll ans = 0;
ll dfs(int u, int k)
{
	ans += k*s[u];
	
	if((int)ara[u].size()==0) return s[u];
	
	ll x = k/(int)ara[u].size();
	vector<ll> ss;
	for(int K = 0; K < (int)ara[u].size();  K++){
		ss.push_back(dfs(ara[u][K], x));
	}
	sort(ss.begin(), ss.end());
	int i = k%(int)ss.size();
	while(i--){
		ans += ss.back();
		ss.pop_back();
	}
	
	return ss.back()+s[u];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll t, n, k;
	
	cin>> t;
	while(t--){
		cin >> n >> k;
		
		ll x;
		for(int K =1 ; K <= n; K++) ara[K].clear();
		for(int K = 2; K <= n; K++){
			cin >> x;
			ara[x].push_back(K);
		}
		for(int K = 1; K <= n; K++) cin >> s[K];
		
		ans = 0;
		dfs(1, k);
		
		cout << ans << "\n";
	}
	
	return 0;
}





































