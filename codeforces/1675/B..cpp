// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n;
	int ara[30];
	
	cin >> t;
	while(t--){
		cin >> n;
		
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		int ans = 0;
		for(int K = n-2; K >= 0; K--){
			if(ara[K+1] == 1 && K){
				ans = -1;
				
				break;
			}
			if(ara[K+1] == 0){
				ans = -1;
				break;
			}
			
			if(ara[K] ==0) continue;
			
			int mid = max(0, (32-__builtin_clz(ara[K]))-(32-__builtin_clz(ara[K+1])));
			
			if((ara[K]>>mid) >= ara[K+1]) mid++;
			
			ans += mid;
			//cout << ' ' << (32-__builtin_clz(ara[K])) << ' ' << (32-__builtin_clz(ara[K+1])) << "\n";

			ara[K] >>= mid;
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































