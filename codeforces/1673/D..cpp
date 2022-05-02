// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9+7;
ll lcm(ll a, ll b)
{
	return a*b/__gcd(a, b);
}
int main()
{
	int t;
	ll ara[2][3];
	vector<ll> v;
	
	cin >> t;
	while(t--){
		for(int K = 0; K < 2; K++){
			for(int L = 0; L < 3; L++) cin >> ara[K][L];
		}
		
		ll a = ara[0][0] + ara[0][1]*(ara[0][2]-1);
		ll b = ara[1][0] + ara[1][1]*(ara[1][2]-1);
		//cout << " " << a << ' ' << b << ' ' << lcm(ara[0][1], ara[1][1]) << "\n";
		
		if(ara[0][0] > ara[1][0] || a < b || ara[1][1]%ara[0][1] != 0 || (ara[1][0]-ara[0][0])%ara[0][1]!=0){
			cout << 0 << "\n";
			continue;
		}
		
		if(b+ara[1][1] > a || ara[1][0]-ara[1][1] < ara[0][0]){
			cout << -1 << "\n";
			continue;
		}
		
		//cout << a << ' ' << b << "\n";
		
		
		ll ans = 0;
		v.clear();
		for(int K = 1; K*K <= ara[1][1]; K++){
			if(ara[1][1] % K == 0){
				v.push_back(K);
				if(K*K != ara[1][1]) v.push_back(ara[1][1]/K);
			}
		}
		
		for(auto x:v){
			ll lc = lcm(ara[0][1], x);
			
			//cout << lc*lc << ' ' << ans << "\n";
			
			ll mid = (ara[1][1]/x);
			if(lc == ara[1][1]) ans = (ans + mid*mid%mod)%mod;
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































