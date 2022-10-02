// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		ll ara[n];
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		sort(ara, ara+n);
		
		ll ans = 0;
		ll x = ara[0]*2-1;
		
		for(int K = 1; K < n; K++){
			if(ara[K] < 2*ara[0]) continue;
			
			ll val = (ara[K]+x-1)/(x) - 1;
			
			//while((ara[K]+val)/(val+1) < ara[0]*2) val++;
			
			//cout << K<< ' ' << val << "\n";
			ans += val;
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































