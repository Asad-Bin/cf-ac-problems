// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n;
	
	cin >> t;
	while(t--){
		int k;
		cin >> n >> k;
		
		ll ara[n];
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		
		ll ans = 0;
		for(int K = 0; K < k; K++){
			ll mx = 0;
			for(int L = K; L < n; L += k) mx = max(mx, ara[L]);
			
			ans += mx;
		}
		
		cout << ans << endl;
	}
	
	return 0;
}




















































