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
			while(ara[K] && ara[K] >= ara[K+1]){
				ara[K] >>= 1LL;
				ans++;
			}
			if(ara[K] == 0 && K){
				ans = -1;
				break;
			}
			if(ara[K+1] == 0){
				ans = -1;
				break;
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}
 
 