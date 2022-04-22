// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 2e5;
ll ara[MX+5], pre[MX+5];
int main()
{
	int t, n, x;
	
	cin >> t;
	while(t--){
		cin >> n >> x;
		
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		sort(ara, ara+n);
		
		pre[0] = ara[0];
		for(int K = 1; K < n; K++) pre[K] = pre[K-1] + ara[K];
		
		int i = n-1;
		ll p, cnt = 0, mid, ans = 0;
		while(i >= 0){
			if(pre[i] > x){
				i--;
				continue;
			}
			
			p = (x-pre[i])/(i+1);
			
			if(p >= cnt){
				ans += (p-cnt)*(i+1);
				cnt = p;
			}
			
			mid = (ll)pre[i]+(ll)cnt*(i+1);
			
			if(mid <= x){
				ans += i+1;
				cnt++;
			}
			else{
				i--;
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































