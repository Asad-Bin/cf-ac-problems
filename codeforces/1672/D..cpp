// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 2e5;
int a[MX+5], b[MX+5], c[MX+5], d[MX+5];
int main()
{
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		memset(c, 0, sizeof c);
		memset(d, 0, sizeof d);
		
		for(int K = 0; K < n; K++){
			cin >> a[K];
			c[a[K]]++;
		}
		for(int K = 0; K < n; K++) cin >> b[K];
		
		bool ans = 1;
		
		if(a[n-1] != b[n-1]) ans = 0;
		int x = a[n-1];
		
		for(int K = n-2, L = n-2; K >= 0 && L >= 0; ){
			if(a[K] != b[L]){
				if(c[b[L]] && x == b[L]){
					d[b[L]]++;
					L--;
				}
				else if(d[a[K]]){
					d[a[K]]--;
					K--;
				}
				else{
					ans = 0;
					break;
				}
			}
			else{
				x = b[L];
				K--;
				L--;
			}
		}
		
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}




















































