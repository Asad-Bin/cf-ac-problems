// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		int x = 0, ara[n];
		for(int K = 0; K < n; K++){
			cin >> ara[K];
			x += ara[K];
		}
		
		bool ok = 0;
		for(int K = 0; K < n; K++) if(ara[K]*n == x) ok = 1;
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}




















































