/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


int main()
{
	long long t, n, a, b;
	
	cin >> t;
	while(t--){
		cin >> n >> a >> b;
		
		if(a == 1){
			if((n-1)%b==0) cout << "YES\n";
			else cout << "NO\n";
		}
		else{
			bool ok = 0;
			
			long long i = 1, q = n%b;
			
			while(i <= n){
				if(i%b==q){
					ok = 1;
					break;
				}
				i *= a;
			}
			
			if(ok) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	
	return 0;
}
