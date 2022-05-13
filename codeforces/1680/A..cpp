// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, a, b, c, d;
	
	cin >> t;
	while(t--){
		cin >> a >> b >> c >> d;
		
		if(c <= b && a <= d){
			cout << max(a, c) << "\n";
		}
		else{
			cout << a+c << "\n";
		}
	}
	
	return 0;
}




















































