// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll t;
	cin >> t;
	while(t--){
		ll n; cin >> n;
		
		ll ara[n];
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		sort(ara, ara+n);
		
		ll ans = 0;
		
		for(int K = 1; K < n-1; K++){
			ans = max(ans, ara[n-1]-ara[K-1] + ara[K]-ara[K-1]);
		}
		for(int K = n-2; K >= 1; K--){
			ans = max(ans, ara[K+1]-ara[0] + ara[K+1]-ara[K]);
		}
		
		
		//int i = 0, j = n-1;
		//while(i+1 < j){
			//if(ara[i] == ara[i+1]) i++;
			//else break;
		//}
		//while(i+1 < j){
			//if(ara[j] == ara[j-1]) j--;
			//else break;
		//}
		
		//ll mx = *max_element(ara+1+i, ara+j), mn = *min_element(ara+1+i, ara+j);
		cout << ans << "\n";
	}
	
	return 0;
}




















































