// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 2e5;
int ara[MX+5];
int main()
{
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		int K = n-1;
		for( ; K >= 0; K--) if(ara[K] != 0) break;
		
		ll mid, num = 0;
		bool ok = 1;
		
		for( ; K > 0; K--){
			mid = ara[K]-num;
			
			if(mid >= 0){
				ok = 0;
				break;
			}
			
			num = -1LL*mid;
		}
		if(ara[0] != num) ok = 0;
		
		if(ok) cout << "Yes\n";
		else cout << "No\n";
	}
	
	return 0;
}




















































