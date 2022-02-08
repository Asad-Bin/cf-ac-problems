/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


const int MX = 2e5;
long long ara[2*MX+5], pre[2*MX+5], lol[2*MX+5];
int main()
{
	long long n, x;
	
	cin >> n >> x;
	
	for(int K = 0; K < n; K++) cin >> ara[K];
	for(int K = n; K < 2*n; K++) ara[K] = ara[K-n];
	n *= 2;
	
	pre[0] = ara[0];
	lol[0] = ara[0]*(ara[0]+1)/2;
	for(int K = 1; K < n; K++){
		pre[K] = ara[K] + pre[K-1];
		
		lol[K] = ara[K]*(ara[K]+1)/2;
		lol[K] += lol[K-1];
	}
	
	long long ans = 0;
	for(int K = 0; K < n; K++){
		long long mid = x + (K>0 ? pre[K-1] : 0);
		
		auto it = lower_bound(pre, pre+n, mid) - pre;
		
		//cout << K << ' ' << it << ' ' << pre[it] << ' ' << mid << ' ' << x << "\n";
		long long hug = pre[it] - (K > 0 ? pre[K-1] : 0);
		//cout << hug << "\n";
		
		if(hug >= x){
			long long cnt = 0;
			int i = K;
			while(ara[i] < hug-x){
				hug -= ara[i];
				i++;
			}
			K = i;
			//cout << hug << ' ' << i << ' ' << ara[i] << "\n";
			cnt = ara[i]*(ara[i]+1)/2 - (hug-x)*(hug-x+1)/2;
			i++;
			//cout << "cnt " << cnt << "\n";
			//while(i <= it){
				//cnt += ara[i]*(ara[i]+1)/2;
				//i++;
			//}
			cnt += lol[it] - (i>0 ? lol[i-1] : 0);
			
			ans = max(ans, cnt);
			//cout << "cnt " << cnt << ' ' << ans << "\n";
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
