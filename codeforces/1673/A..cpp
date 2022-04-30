// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, ans;
	string s;
	
	cin >> t;
	while(t--){
		cin >> s;
		
		int n = (int)s.length();
		
		int bob = 0;
		
		if(n%2==0){
			ans = 0;
			for(int K = 0; K < n; K++) ans += (s[K]-'a')+1;
		}
		else{
			ans = 0;
			for(int K = 0; K < n; K++) ans += (s[K]-'a')+1;
			
			ans -= min(s[0]-'a'+1, s[n-1]-'a'+1);
			bob += min(s[0]-'a'+1, s[n-1]-'a'+1);
		}
		
		if(ans > bob) cout << "Alice " << ans-bob << "\n";
		else cout << "Bob " << bob-ans << "\n";
	}
	
	return 0;
}




















































