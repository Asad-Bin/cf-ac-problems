/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


int main()
{
	long long n, k;
	
	cin >> n >> k;
	
	long long ara[n], save[n];
	memset(save, 0LL, sizeof save);
	
	for(int K = 0; K < n; K++) cin >> ara[K];
	
	long long ans = 0, sum = 0, cnt = 0;
	for(int K = n-1; K >= 0; K--){
		sum -= cnt;
		cnt -= save[K];
		ara[K] -= sum;
		
		if(ara[K] <= 0) continue;
		
		long long x = min((long long)K+1, k);
		long long mid = (ara[K]+x-1)/x;
		
		ans += mid;
		sum += mid*x;
		cnt += mid;
		if(K >= x){
			save[K-x] = mid;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

























