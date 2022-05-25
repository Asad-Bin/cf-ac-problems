// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 1e5;
int ara[MX+5], b[MX+5];
int main()
{
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		for(int K = 0; K < n; K++){
			cin >> ara[K];
			b[K] = -1;
		}
		
		sort(ara, ara+n);
		
		int K = n-1, L;
		for(K = n-1, L = n-1; K >= 0 && L >= 0; K--, L -= 2){
			b[L] = ara[K];
		}
		
		for(L = n-2; L >= 0; L -= 2, K--){
			b[L] = ara[K];
		}
		
		bool ok = 1;
		for(K = 1; K < n-1; K++){
			if(b[K] > b[K+1] && b[K] > b[K-1]) {}
			else if(b[K] < b[K+1] && b[K] < b[K-1]) {}
			else ok = 0;
		}
		
		if(b[0] > b[n-1] && b[0] > b[1]) {}
		else if(b[0] < b[n-1] && b[0] < b[1]) {}
		else ok = 0;
		
		if(b[n-1] > b[0] && b[n-1] > b[n-2]) {}
		else if(b[n-1] < b[0] && b[n-1] < b[n-2]) {}
		else ok = 0;
		
		if(ok){
			cout << "YES\n";
			for(K = 0; K < n; K++) cout << b[K] << ' ';
			cout << "\n";
		}
		else cout << "NO\n";
	}
	
	return 0;
}




















































