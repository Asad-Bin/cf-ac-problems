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
		
		int ara[n];
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		bool ok = 1;
		for(int K = 1; K < n; K++){
			if(ara[K] != ara[K-1]){
				ok = 0;
				break;
			}
		}
		if(ok){
			cout << "YES\n";
			continue;
		}
		
		ok = 1;
		for(int K = n-1; K >= 1; K--){
			if(abs(ara[K]-ara[K-1]) % ara[0] != 0){
				ok = 0;
				break;
			}
		}
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
 
 
 
