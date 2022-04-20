/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


int main()
{
	long long n, C, c, d, h;
	
	cin >> n >> C;
	long long ara[C+1] = {0};
	
	for(int K = 0; K < n; K++){
		cin >> c >> d >> h;
		
		ara[c] = max(ara[c], h*d);
	}
	
	for(long long K = 1; K <= C; K++){
		for(long long L = K; L <= C; L+=K){
			ara[L] = max(ara[L], ara[K]*L/K);
		}
	}
	for(long long K = 2; K <= C; K++) ara[K] = max(ara[K], ara[K-1]);
	
	long long m;
	cin >> m;
	for(long long K = 0; K < m; K++){
		cin >> d >> h;
		
		long long x = upper_bound(ara+1, ara+C+1, d*h)-ara;
		
		if(x > C) cout << "-1 ";
		else cout << x << ' ';
	}
	cout << "\n";
	
	return 0;
}

























