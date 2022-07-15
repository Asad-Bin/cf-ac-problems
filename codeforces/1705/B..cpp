// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		ll ara[n];
		ll ans = 0, cnt = 0;
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		for(int K = n-2; K >= 0; K--){
			if(ara[K] == 0) cnt++;
			else{
				ans += ara[K]+cnt;
				
				cnt = 0;
			}
		} 
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































