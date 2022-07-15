// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ara[45];
ll c, n;
vector<pair<ll, ll> > v;
string s;

char calc(ll x)
{
	if(x >= 1 && x <= n) return s[x-1];
	
	auto it = lower_bound(ara, ara+c+1, x)-ara;
	//cout << "it = " << it << "\n";
	
	ll val = x - (it ? ara[it-1] : 0LL);

	val = v[it].first + val - 1;
	
	//cout << "val = " << val << "\n";
	
	return calc(val);
}
int main()
{
	ll t, q, x, y;
	
	cin >> t;
	while(t--){
		cin >> n >> c >> q;
		cin >> s;
		
		v.clear();
		for(int K = 0; K < c; K++) ara[K] = 0;
		
		v.push_back({1, n});
		ara[0] = n;
		for(int K = 1; K <= c; K++){
			cin >> x >> y;
			v.push_back({x, y});
			ara[K] = y-x+1;
		}
		for(int K = 1; K <= c; K++) ara[K] += ara[K-1];
		
		for(int K = 0; K < q; K++){
			cin >> x;
			
			cout << calc(x) << "\n";
		}
	}
	
	return 0;
}




















































