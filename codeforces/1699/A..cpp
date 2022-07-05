// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x)        cerr << #x << " == " << (x) << '\n';


int main()
{
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		if(n%2==0) cout << 0 << ' ' << n/2 << ' ' << n/2 << "\n";
		else cout << -1 << "\n";
	}
	
	return 0;
}




















































