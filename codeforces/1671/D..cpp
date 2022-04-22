// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int MX = 2e5;
ll ara[MX+5];
int main()
{
	ll t, n, x;
	
	cin >> t;
	while(t--){
		cin >> n >> x;
		
		ll mn = MX+5, mx = 0;
		for(int K = 0; K < n; K++){
			cin >> ara[K];
			mn = min(mn, ara[K]);
			mx = max(mx, ara[K]);
		}
		
		ll ans = 0;
		for(int K = 1; K < n; K++) ans += abs(ara[K]-ara[K-1]);
		
		if(x > mx) ans += min({abs(ara[0]-x), abs(ara[n-1]-x), 2*abs(mx-x)});
		if(1 < mn) ans += min({abs(ara[0]-1), abs(ara[n-1]-1), 2*abs(mn-1)});
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































