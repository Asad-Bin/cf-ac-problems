// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n, l, r;
	
	cin >> t;
	while(t--){
		cin >> n >> l >> r;
		
		bool ok = 1;
		int ara[n+1];
		for(int K = 1; K <= n; K++){
			ara[K] = (l+K-1)/K;
			ara[K] = ara[K]*K;
			if(ara[K] > r) ok = 0;
		}
		
		if(ok){
			cout << "YES\n";
			for(int K = 1; K <= n; K++) cout << ara[K] << ' ';
			cout << "\n";
		}
		else cout << "NO\n";
	}
	
	return 0;
}




















































