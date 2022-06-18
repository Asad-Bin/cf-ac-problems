// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 1000;
int ara[MX+5][MX+5], dp[MX+5][MX+5];
int main()
{
	int t, n, m;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		for(int K = 0; K < n; K++){
			for(int L = 0; L < m; L++){
				cin >> ara[K][L];
				if(ara[K][L] == -1) ara[K][L] = 0;
			}
		}
		
		if((n+m)%2==0){
			cout << "NO\n";
			continue;
		}
		
		int sum = (n+m-1)/2;
		
		for(int K = 0; K < n; K++){
			for(int L = 0; L < m; L++){
				dp[K][L] = ara[K][L];
				if(K) dp[K][L] = max(dp[K][L], dp[K-1][L]+ara[K][L]);
				if(L) dp[K][L] = max(dp[K][L], dp[K][L-1]+ara[K][L]);
			}
		}
		if(dp[n-1][m-1] < sum){
			cout << "NO\n";
			continue;
		}
		
		for(int K = 0; K < n; K++){
			for(int L = 0; L < m; L++){
				if(ara[K][L] == 0) ara[K][L] = 1;
				else ara[K][L] = 0;
			}
		}
		
		for(int K = 0; K < n; K++){
			for(int L = 0; L < m; L++){
				dp[K][L] = ara[K][L];
				if(K) dp[K][L] = max(dp[K][L], dp[K-1][L]+ara[K][L]);
				if(L) dp[K][L] = max(dp[K][L], dp[K][L-1]+ara[K][L]);
			}
		}
		if(dp[n-1][m-1] < sum){
			cout << "NO\n";
			continue;
		}
		
		cout << "YES\n";
	}
	
	return 0;
}




















































