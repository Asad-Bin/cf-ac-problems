// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n, x;
	
	cin >> t;
	while(t--){
		cin >> n >> x;
		int ara[2*n];
		for(int K = 0; K < 2*n; K++) cin >> ara[K];
		
		sort(ara, ara+2*n);
		
		bool ok = 1;
		for(int K = 0; K < n; K++){
			if(ara[n+K]-ara[K] < x){
				ok = 0;
				break;
			}
		}
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}




















































