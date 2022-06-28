// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n, k;
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		
		int ara[n];
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		if(k == 1){
			cout << (n-2+1)/2 << "\n";
			continue;
		}
		
		int ans = 0;
		
		for(int K = 1; K < n-1; K++){
			if(ara[K] > ara[K-1]+ara[K+1]) ans++;
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































