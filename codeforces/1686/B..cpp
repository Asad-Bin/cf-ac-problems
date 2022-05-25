// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		int pre = -1, x, ans = 0;
		for(int K = 0; K < n; K++){
			cin >> x;
			
			if(pre > x){
				ans++;
				pre = -1;
			}
			else{
				pre = x;
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































