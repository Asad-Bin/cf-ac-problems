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
		
		if(n == 2 || n%2LL != 0LL){
			cout << -1 << "\n";
			
			continue;
		}
		
		ll mn = 0, mx = 0;
		
		if(n%4LL==0LL){
			mx = n/4LL;
		}
		else{
			mx = n/4LL;
		}
		
		if(n%6LL==0LL){
			mn = n/6LL;
		}
		else{
			mn = n/6LL+1;
		}
		
		cout << mn << ' ' << mx << "\n";
	}
	
	return 0;
}




















































