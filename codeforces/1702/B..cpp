// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n;
	string s;
	set<char> ss;
	
	cin >> t;
	while(t--){
		cin >> s;
		
		n = (int)s.length();
		
		int ans = 0;
		ss.clear();
		
		for(int K = 0; K < n; K++){
			ss.insert(s[K]);
			
			if((int)ss.size() == 4){
				ss.clear();
				ans++;
				ss.insert(s[K]);
			}
		}
		if(!ss.empty()) ans++;
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































