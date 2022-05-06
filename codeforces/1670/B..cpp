// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n, k;
	string s;
	char c;
	vector<int> mp(30);
	
	cin >> t;
	while(t--){
		cin >> n >> s >> k;
		
		fill(mp.begin(), mp.end(), 0);
		for(int K = 0; K < k; K++){
			cin >> c;
			mp[c-'a']++;
		}
		
		int cnt = 0, ans = 0;
		int f = 0;
		for(int K = 0; K < n; K++){
			if(mp[s[K]-'a']){
				ans = max(ans, cnt+f);
				cnt = 0;
				f = 1;
			}
			else{
				cnt++;
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































