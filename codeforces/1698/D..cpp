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
		if(n == -1) return 0;
		
		int l = 1, r = n, x, cnt;
		while(l < r){
			int mid = (l+r)/2;
			
			cnt = 0;
			cout << '?' << ' ' << l << ' ' << mid << endl;
			
			for(int K = l; K <= mid; K++){
				cin >> x;
				if(x == -1) return 0;
				if(x >= l && x <= mid) cnt++;
			}
			
			if(cnt&1){
				r = mid;
			}
			else{
				l = mid+1;
			}
		}
		
		cout << '!' << ' ' << l << endl;
	}
	
	return 0;
}




















































