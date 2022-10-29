// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll t;
	cin >> t;
	vector<pair<ll, ll> > v;
	
	while(t--){
		int n; cin >> n;
		
		ll a, b;
		ll ans = 0;
		
		v.clear();
		for(int K = 0; K < n; K++){
			cin >> a >> b;
			if(a < b) swap(a, b);
			v.push_back({a, b});
			
			ans += 2*a+2*b;
		}
		
		sort(v.begin(), v.end());
		
		for(int K = 1; K < n; K++){
			ans -= 2*min(v[K-1].first, v[K].first);
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































