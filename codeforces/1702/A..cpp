// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		ll x = 1;
		
		while(x*10LL <= n) x *= 10LL;
		
		cout << n-x << "\n";
	}
	
	return 0;
}




















































