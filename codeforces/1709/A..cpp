// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, x, a[4];
	
	cin >> t;
	while(t--){
		cin >> x >> a[1] >> a[2] >> a[3];
		
		if(a[x] != 0 && a[a[x]] != 0) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}




















































