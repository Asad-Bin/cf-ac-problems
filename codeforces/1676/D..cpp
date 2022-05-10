// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n, m;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		int ara[n][m];
		for(int K = 0; K < n; K++){
			for(int L = 0; L < m; L++) cin >> ara[K][L];
		}
		
		ll ans = 0;
		for(int K = 0; K < n; K++){
			for(int L = 0; L < m; L++){
				ll cnt  = ara[K][L];
				//cout << K << ' ' << L << ' ' << ara[K][L] << ' ' << cnt << ' ' << ans << "\n";
				
				int i = K-1, j = L+1;
				while(i >= 0 && j < m){
					cnt += ara[i][j];
					i--;
					j++;
				}
				//cout << K << ' ' << L << ' ' << ara[K][L] << ' ' << cnt << ' ' << ans << "\n";
				
				i = K+1, j = L-1;
				while(i < n && j >= 0){
					cnt += ara[i][j];
					i++;
					j--;
				}
				//cout << K << ' ' << L << ' ' << ara[K][L] << ' ' << cnt << ' ' << ans << "\n";
				
				i = K-1, j = L-1;
				while(i >= 0 && j >= 0){
					cnt += ara[i][j];
					i--;
					j--;
				}
				//cout << K << ' ' << L << ' ' << ara[K][L] << ' ' << cnt << ' ' << ans << "\n";
				
				i = K+1, j = L+1;
				while(i < n && j < m){
					cnt += ara[i][j];
					i++;
					j++;
				}
				
				ans = max(ans, cnt);
				//cout << K << ' ' << L << ' ' << ara[K][L] << ' ' << cnt << ' ' << ans << "\n\n";
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































