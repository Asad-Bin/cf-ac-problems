/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


const int MX = 1e7;
int dp[MX+5][4];
const int mod = 1e9+7;
int main()
{
	int n;
	
	cin >> n;
	
	dp[1][0] = dp[1][1] = dp[1][2] = 1;
	dp[1][3] = 0;
	dp[2][0] = dp[1][1]+dp[1][2];
	dp[2][1] = dp[1][0]+dp[1][2];
	dp[2][2] = dp[1][0]+dp[1][1];
	dp[2][3] = dp[1][0]+dp[1][1]+dp[1][2];
	
	for(int K = 3; K <= n; K++){
		dp[K][0] = ((dp[K-1][1] + dp[K-1][2])%mod + dp[K-1][3])% mod;
		dp[K][1] = ((dp[K-1][0] + dp[K-1][2])%mod + dp[K-1][3])% mod;
		dp[K][2] = ((dp[K-1][1] + dp[K-1][0])%mod + dp[K-1][3])% mod;
		dp[K][3] = ((dp[K-1][1] + dp[K-1][2])%mod + dp[K-1][0])% mod;
	}
	
	cout << dp[n][3] << "\n";
	
	return 0;
}
