// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, a, b, c, x, y;
	
	cin >> t;
	while(t--){
		cin >> a >> b >> c >> x >> y;
		
		x -= a;
		y -= b;
		
		if(x > 0 && c < x){
			cout << "NO\n";
			continue;
		}
		
		if(x > 0) c -= x;
		
		if((y > 0 && c >= y) || (y <= 0)) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}




















































