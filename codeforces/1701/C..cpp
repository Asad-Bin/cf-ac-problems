// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 2e5;
vector<int> v(MX+5), ara;
int n, m;

bool test(ll ans)
{
	ll task = 0;
	for(int K = 0; K < n; K++){
		if(ara[K] > ans) task += (ll)2*(ara[K]-ans);
		else if(ara[K] < ans){
			task -= (ll)(ans-ara[K])/2*2;
		}
	}
	
	//cout << "ans = " << ans << ' ' << task << "\n";
	if(task <= 0) return true;
	return false;
}
int main()
{
	int t, x;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		for(int K = 1; K <= n; K++) v[K] = 0;
		for(int K = 1; K <= m; K++){
			cin >> x;
			v[x]++;
		}
		
		ara.clear();
		for(int K = 1; K <= n; K++) ara.push_back(v[K]);
		
		//for(auto it:ara) cout << it << ' ';
		//cout << "\n";
		ll l = 1, r = m, mid;
		while(l < r){
			mid = (l+r)/2;
			
			if(test(mid)){
				r = mid;
			}
			else{
				l = mid+1;
			}
		}
		
		cout << l << "\n";
	}
	
	return 0;
}




















































