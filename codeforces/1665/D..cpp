/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


int main()
{
	long long t, gcd;
	
	cin >> t;
	while(t--){
		long long i = 0, r = 0;
		
		while(i < 30){
			cout << "? " << (1LL<<i)-r << ' ' << (1LL<<i)-r+(1LL<<(i+1)) << endl;
			cin >> gcd;
			
			if(gcd == (1LL<<(i+1))){
				r += (1LL<<i);
			}
			
			i++;
		}
		
		cout << "! " << r << endl;
	}
	
	return 0;
}

























