// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MX = 2e5;
vector<ll> ara[MX+5];
ll v[MX+5][2];

pair<ll, ll> calc(ll u, ll p)
{
	pair<ll, ll> ans = {0, 0}, mid;
	for(ll K = 0; K < (ll)ara[u].size(); K++){
		if(ara[u][K] != p){
			mid = calc(ara[u][K], u);
			
			ans.first += mid.first;
			ans.second += mid.second;
		}
	}
	
	if(v[u][0] > ans.second){
		ans.first++;
		ans.second = v[u][1];
	}
	else{
		ans.second = min(ans.second, v[u][1]);
	}
	
	return ans;
}

int main()
{
	ll t, n, x;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		for(ll K = 1; K <= n; K++) ara[K].clear();
		for(ll K = 2; K <= n; K++){
			cin >> x;
			
			ara[x].push_back(K);
			ara[K].push_back(x);
		}
		
		for(ll K = 1; K <= n; K++){
			cin >> v[K][0] >> v[K][1];
		}
		
		pair<ll, ll> ans = calc(1, -1);
		cout << ans.first << "\n";
	}
	
	return 0;
}




















































