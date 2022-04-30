// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n;
	string s;
	map<char, int> mp, cnt;
	
	cin >> t;
	while(t--){
		cin >> s;
		
		n = (int)s.length();
		
		mp.clear();
		for(int K = 0; K < n; K++) mp[s[K]] = 1;
		
		cnt.clear();
		bool ok = 1;
		for(auto x:mp){
			cnt.clear();
			for(int K = 0; K < n; K++){
				if(s[K] == x.first){
					cnt.clear();
				}
				else{
					cnt[s[K]]++;
					if(cnt[s[K]] == 2){
						ok = 0;
						//cout << x.first << ' ' << K << "\n";
					}
				}
			}
		}
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}




















































