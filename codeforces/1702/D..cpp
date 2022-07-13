// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n, p;
	string s;
	map<char, int> mp;
	
	cin >> t;
	while(t--){
		cin >> s >> p;
		
		n = (int)s.length();
		
		int cost = 0;
		for(int K = 0; K < n; K++){
			cost += (s[K]-'a'+1);
			mp[s[K]]++;
		}
		
		for(char K = 'z'; K >= 'a'; K--){
			while(cost > p && mp[K]){
				cost -= (K-'a'+1);
				mp[K]--;
			}
		}
		
		string str = "";
		for(int K = 0; K < n; K++){
			if(mp[s[K]]){
				str += s[K];
				mp[s[K]]--;
			}
		}
		
		cout << str << "\n";
	}
	
	return 0;
}




















































