// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 1e5;
ll ara[MX+5], pre[MX+5], suf[MX+5];

int main()
{
	ll n, m, l, r;
	
	cin >> n >> m;
	
	for(int K = 0; K < n; K++) cin >> ara[K];
	
	pre[0] = 0;
	for(int K = 1; K < n; K++){
		pre[K] = max(ara[K-1]-ara[K], 0LL) + pre[K-1];
		//cout << K << ' ' << pre[K] << "\n";
	}
	
	suf[n-1] = 0;
	for(int K = n-2; K >= 0; K--){
		suf[K] = max(ara[K+1]-ara[K], 0LL) + suf[K+1];
		//cout << K << ' ' << suf[K] << "\n";
	}
	
	while(m--){
		cin >> l >> r;
		l--;
		r--;
		
		if(l <= r){
			cout << pre[r]-pre[l] << "\n";
		}else{
			cout << suf[r]-suf[l] << "\n";
		}
	}
	
	return 0;
}




















































