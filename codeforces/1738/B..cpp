// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n, k;
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		
		ll v[k], ara[n];
		for(int K = 0; K < k; K++) cin >> v[K];
		
		bool ok = 1;
		ll mn = 2e9;
		for(int K = n-1, L = k-1; L > 0; L--, K--){
			ara[K] = v[L] - v[L-1];
			if(ara[K] > mn) ok = 0;
			mn = min(mn, ara[K]);
		}
		
		int val = (n-k+1);
		
		if(n == k){
			if(v[0] > mn) ok = 0;
		}
		else if(ok){
			if(val*mn < v[0]) ok = 0;
		}
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}




















































