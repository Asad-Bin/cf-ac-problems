/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


const int MX = 1e5;
long long ara[MX+5];
int main()
{
	long long t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		long long mx = -2e9+5, val = 0;
		for(int K = 0; K < n; K++){
			cin >> ara[K];
			mx = max(mx, ara[K]);
			val = max(val, mx-ara[K]);
		}
		
		long long ans = 0;
		while((1LL<<ans)-1 < val) ++ans;
		
		cout << ans << "\n";
	}
	
	return 0;
}
