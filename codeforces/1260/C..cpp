// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x)        cerr << #x << " == " << (x) << '\n';


int main()
{
	ll t, r, b, k;
	
	cin >> t;
	while(t--){
		cin >> r >> b >> k;
		
		ll g = __gcd(r, b);
		r /= g;
		b /= g;
		if(r > b) swap(r, b);
		
		if(b > (k-1)*r+1) cout << "REBEL\n";//else if((r-1)/b+1 >= k) cout << "REBEL\n";
		else cout << "OBEY\n";
	}
	
	return 0;
}




















































