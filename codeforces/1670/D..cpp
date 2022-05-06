// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MX = 1e5;
ll ara[MX+5];
int main()
{
	ll t, n;
	
	ll i = 0;
	while(i <= MX+1){
		if(i%2==0) ara[i] = i*2+i*2+2+i*2+4;
		
		if(i) ara[i] += ara[i-1];
		//cout << i << ' ' << ara[i]<< "\n";
		i++;
	}
	
	cin >> t;
	while(t--){
		cin >> n;
		
		auto it = lower_bound(ara, ara+MX+1, n)-ara;
		it -= 2;
		//--it;
		
		ll ans = 1, mid, tot = 0;
		
		if(it >= 0){
			i = it;
			ans = (i/2+1)*3;
			tot = ara[i];
			
			i += 2;
		}
		else i = 0;
		
		while(tot < n){
			mid = i<<1LL;
			tot += mid;
			if(mid) ans++;
			
			if(tot >= n) break;
			mid += 2;
			tot += mid;
			ans++;
			
			if(tot >= n) break;
			mid += 2;
			tot += mid;
			ans++;
			
			i += 2;
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































