// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n;
	map<int, int> mp;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		int ara[n];
		int a = 0, b = 0, c = 0;
		
		mp.clear();
		for(int K = 0; K < n; K++){
			cin >> ara[K];
			
			mp[ara[K]]++;
			
			if(ara[K] < 0) a++;
			else if(ara[K] > 0) b++;
			else c++;
		}
		
		sort(ara, ara+n);
		
		if(a >= 3 || b >= 3){
			cout << "NO\n";
		}
		else if(a == 2 && b == 2){
			if(c) cout << "NO\n";
			else if(mp[ara[0]+ara[1]+ara[n-1]] && mp[ara[0]+ara[1]+ara[n-2]] && mp[ara[0]+ara[n-1]+ara[n-2]] && mp[ara[1]+ara[n-1]+ara[n-2]]) cout << "YES\n";
			else cout << "NO\n";
		}
		else if(a == 2){
			if(c) cout << "NO\n";
			else if(mp[ara[0]+ara[1]+ara[2]]) cout << "YES\n";
			else cout << "NO\n";
		}
		else if(b == 2){
			if(c) cout << "NO\n";
			else if(mp[ara[0]+ara[1]+ara[2]]) cout << "YES\n";
			else cout << "NO\n";
		}
		else if(a == 1 && b == 1){
			if(mp[ara[0]+ara[n-1]]) cout << "YES\n";
			else cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
	
	return 0;
}




















































