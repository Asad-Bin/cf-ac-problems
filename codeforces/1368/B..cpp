/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;



int main()
{
	string out = "codeforces";
	
	long long k;
	cin >> k;
	
	long long mul = 1;
	long long ara[10];
	
	for(int K = 0; K < 10; K++) ara[K] = 1LL;
	
	while(mul < k){
		for(int K = 0; K < 10; K++){
			mul /= ara[K];
			ara[K]++;
			mul *= ara[K];
			
			//cout << K << ' ' << ara[K] << ' ' << mul << "\n";
			if(mul >= k) break;
		}
	}
	
	
	for(int K = 0; K < 10; K++){
		while(ara[K]--) cout << out[K];
	}
	
	return 0;
}
