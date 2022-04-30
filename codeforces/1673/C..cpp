// . . . Bismillahir Rahmanir Rahim . . .
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int mod = 1e9+7;
int p;
vector<int> v;
 
int dp[40005];
int calc(int sum)
{
	dp[0] = 1;
	for(int K=0; K<p; K++){
        for(int L=1; L<=sum; L++){
            if(L>=v[K]) dp[L] = (dp[L]+dp[L-v[K]])%mod;
        }
    }
    return dp[sum]%mod;
}
int main()
{
	int t, n;
	
	for(int K = 1; K <= 9; K++) v.push_back(K);
	for(int K = 1; K <= 9; K++) v.push_back(K*10+K);
	for(int K = 0; K <= 9; K++){
		for(int L = 1; L <= 9; L++) v.push_back(L*100+K*10+L);
	}
	for(int K = 1; K <= 9; K++){
		for(int L = 0; L <= 9; L++) v.push_back(K*1000+L*100+L*10+K);
	}
	for(int M = 1; M <= 3; M++){
		for(int K = 0; K <= 9; K++){
			for(int L = 0; L <= 9; L++) v.push_back(M*10000+L*1000+K*100+L*10+M);
		}
	}
	p = (int)v.size();
	sort(v.begin(), v.end());
	//for(auto x:v) cout << x << "\n";
	
		memset(dp, 0, sizeof dp);
	calc(40000);	
	
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		
		
		//int ans = calc(n);
		//for(int K = 0; K < p; K++) if(n >= v[K]) ans += (ll)calc(K, n-v[K]);
		
		printf("%d\n", dp[n]);	
	}
	
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
