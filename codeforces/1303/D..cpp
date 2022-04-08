/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
const ll MXL = 1e18+7;
ll m, cnt[80];


int main()
{
	ll t, n, x;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		ll sum = 0;
		memset(cnt, 0LL, sizeof cnt);
		for(int K = 0; K < m; K++){
			cin >> x;
			cnt[(int)log2(x)]++;
			
			sum += x;
		}
		
		if(sum < n){
			cout << "-1\n";
			continue;
		}
		
		ll i = 0, ans = 0;
		
		while(i < 60){
			if(n&(1LL<<i)){
				if(cnt[i]){
					cnt[i]--;
				}
				else{
					while(i < 60 && !cnt[i]){
						i++;
						ans++;
					}
					cnt[i]--;
					
					continue;
				}
				
				//n ^= (1LL<<i);
			}
			cnt[i+1] += cnt[i]/2;
			i++;
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}
