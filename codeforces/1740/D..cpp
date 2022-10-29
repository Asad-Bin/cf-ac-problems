// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t; cin >> t;
	set<ll> ss;
	
	while(t--){
		ll n,m, k;
		cin >> n >> m >> k;
		
		ss.clear();
		ll x, i = k;
		bool ok = 1;
		ll mx = n*m - 2;
		
		while(k--){
			cin >> x;
			
				ss.insert(x);
				if((ll)ss.size() >= mx) ok = 0;
			
				while(!ss.empty() && *ss.rbegin() == i){
					i--;
					ss.erase(*ss.rbegin());
				}
		}
		
		if(ok) cout << "YA\n";
		else cout << "TIDAK\n";
	}
	
	
	return 0;
}




















































