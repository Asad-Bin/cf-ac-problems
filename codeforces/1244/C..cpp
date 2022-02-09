/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


int main()
{
	long long n, p, w, d;
	
	
	cin >> n >> p >> w >> d;
	
	for(long long K = 0; K < w; K++){
		long long mid = p - K*d;
		
		if(mid >= 0 && mid%w == 0 && mid/w+K <= n){
			cout << mid/w << ' ' << K << ' ' << n-mid/w-K << "\n";
			return 0;
		}
	}
	
	cout << "-1\n";
	
	return 0;
}
