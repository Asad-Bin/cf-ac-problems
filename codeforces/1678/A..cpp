// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		int ara[n], cnt[105] = {0};
		
		for(int K = 0; K < n; K++){
			cin >> ara[K];
			cnt[ara[K]]++;
		}
		
		bool ok = 0;
		for(int K = 1; K <= 100; K++) if(cnt[K] > 1) ok = 1;
		
		if(cnt[0]){
			cout << n-cnt[0] << "\n";
		}
		else {
			if(ok) cout << n << "\n";
			else cout << n+1 << "\n";
		}
	}
	
	return 0;
}




















































