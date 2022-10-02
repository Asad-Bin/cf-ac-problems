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
		
		ll mid = n - 3 - 1;
		mid = (mid+1)/3;
		if(mid == 0) mid = 1;
		
		cout << mid-1 << "\n";
	}
	
	return 0;
}




















































