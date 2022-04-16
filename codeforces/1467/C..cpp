/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


const int MX = 3e5;
int n[3];
long long a[3][MX+5];

long long calc()
{
	long long ans = 0, m1 = a[1][0], m2 = a[2][0], s1 = 0, s2 = 0;
	
	for(int K = 0; K < n[0]; K++) ans += a[0][K];
	for(int K = 1; K < n[1]; K++) s1 += a[1][K];
	for(int K = 1; K < n[2]; K++) s2 += a[2][K];
	
	ans += max({s1+m1 - s2-m2, s2+m2 - s1-m1, s2+s1 - m1-m2});
	return ans;
}

int main()
{
	cin >> n[0] >> n[1] >> n[2];
	
	for(int K = 0; K < 3; K++){
		for(int L = 0; L < n[K]; L++) cin >> a[K][L];
		sort(a[K], a[K]+n[K]);
	}
	
	long long ans = -1e18;
	ans = max(ans, calc());
	
	swap(a[0], a[1]), swap(n[0], n[1]);
	ans = max(ans, calc());
	
	swap(a[0], a[2]), swap(n[0], n[2]);
	ans = max(ans, calc());
	
	cout << ans << "\n";
	
	return 0;
}

























