// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif


const int N = 1e8;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n, q; cin >> n >> q;
	
	map<int, vector<int> > mp_od, mp_ev;
	mp_ev[0].push_back(0);
	
	ll ara[n+1], v[n+1];
	ara[0] = 0;
	for(ll K = 1; K <= n; K++) cin >> v[K];
	ara[1] = v[1];
	mp_od[ara[1]].push_back(1);
	
	for(ll K = 2; K <= n; K++){
		ara[K] = v[K]^ara[K-1];
		
		if(K&1) mp_od[ara[K]].push_back(K);
		else mp_ev[ara[K]].push_back(K);
	}
	ll pre[n+1];
	pre[1] = v[1];
	pre[0] = 0;
	for(ll K = 2; K <= n; K++) pre[K] = v[K] + pre[K-1];
	
	
	ll l, r;
	while(q--){
		cin >> l >> r;
		
		if(pre[r]-pre[l-1] == 0) cout << 0 << "\n";
		else if((ara[r]^ara[l-1]) == 0LL && (r-l+1) != 2){
			if((r-l+1)%2LL==0){
				if(v[l] == 0 || v[r] == 0){
					cout << 1 << "\n";
					continue;
				}
				
				if(!(r&1)){
					auto it = upper_bound(mp_od[ara[r]].begin(), mp_od[ara[r]].end(), l);
					
					if(it != mp_od[ara[r]].end() && *it < r) cout << 2 << "\n";
					else cout << -1 << "\n";
				}
				else{
					auto it = upper_bound(mp_ev[ara[r]].begin(), mp_ev[ara[r]].end(), l);
					
					if(it != mp_ev[ara[r]].end() && *it < r) cout << 2 << "\n";
					else cout << -1 << "\n";
				}
			}
			else cout << 1 << "\n";
		}
		else cout << -1 << "\n";
	}
	
	return 0;
}





































