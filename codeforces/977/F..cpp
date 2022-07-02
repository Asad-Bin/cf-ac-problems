// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
#define debug(x)        cerr << #x << " == " << (x) << '\n';


int main()
{
	int n;
	
	cin >> n;
	
	map<int, int> dp;
	int ara[n];
	
	for(int K = 0; K < n; K++) cin >> ara[K];
	
	int ans = 0, last = 0;
	for(int K = 0; K < n; K++){
		dp[ara[K]] = dp[ara[K]-1]+1;
		
		if(ans < dp[ara[K]]) last = ara[K];
		ans = max(ans, dp[ara[K]]);
	}
	
	cout << ans << "\n";
	vector<int> v;
	for(int K = n-1; ans>0 && K >= 0; K--){
		if(ara[K] == last){
			v.push_back(K);
			last--;
		}
	}
	
	reverse(v.begin(), v.end());
	for(auto x:v) cout << x+1 << ' ';
	cout << "\n";
	
	return 0;
}




















































