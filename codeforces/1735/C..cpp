// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n;
	string s;
	
	cin >> t;
	while(t--){
		cin >> n >> s;
		//cout << n << ' ' << s << "\n";
		
		string ans;
		map<char, char> mp;
		ans.assign(n, 'a');
		set<char> ss;
		for(int K =  0; K < 26; K++) ss.insert('a'+K);
		
		for(int K = 0; K < n; K++){
			if(mp[s[K]] >= 'a' && mp[s[K]] <= 'z'){
				ans[K] = mp[s[K]];
			}
			else{
				char c = *ss.begin();
				ss.erase(ss.begin());
				
				
				vector<char> v;
				//if(c == s[K]){
					//char ch = c;
					//c = *ss.begin();
					//ss.erase(ss.begin());
					//v.push_back(ch);
				//}
				
				while(!ss.empty()){
					bool ok = 1;
					char ch = c;
					if(ch == s[K]){
						ok = 0;
						//break;
					}
					while(mp[ch] >= 'a' && mp[ch] <= 'z'){
						ch = mp[ch];
						if(ch == s[K]){
							ok = 0;
							//break;
						}
					}
					//cout << K << ' '  << ok << ' ' << "\n";
					if(ok == 0){
						ch = c;
						c = *ss.begin();
						ss.erase(ss.begin());
						v.push_back(ch);
						//break;
					}
					else break;
				}
				
				for(auto it:v) ss.insert(it);
				
				
				mp[s[K]] = c;
				
				ans[K] = c;
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































