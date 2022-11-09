// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n; cin >> n;
	
	set<ll> ss;
	ll x;
	for(int K = 0; K < n; K++){
		cin >> x;
		ss.insert(x);
	}
	
	vector<ll > v, ara;
	for(auto it:ss){
		v.push_back(it);
	}
	
	n = (int)v.size();
	for(int K = 1; K < n; K++) ara.push_back(v[K]-v[K-1]);
	
	
	sort(ara.begin(), ara.end());
	//for(auto it:ara) cout << it << ' ';
	//cout << "\n";
	
	vector<ll> pre = ara;
	for(int K = 1; K < (int)ara.size(); K++) pre[K] += pre[K-1];
	
	ll q, l, r;
	cin >> q;
	while(q--){
		cin>> l >> r;
		
		auto it = lower_bound(ara.begin(), ara.end(), r-l+1) - ara.begin();
		
		//debug(it);
		ll ans = 0;
		
		if(it) ans = pre[it - 1];
		ans += (n-it)*(r-l+1);
		
		cout << ans << " ";
	}
	cout << "\n";
	
	return 0;
}





































