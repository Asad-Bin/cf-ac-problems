// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n, k, mid;
	string s;
	vector<char> v;
	map<char, int> mp;
	
	cin >> t;
	while(t--){
		cin >> n >> k >> s;
		
		v.clear();
		mp.clear();
		for(int K = 0; K < n; K++){
			if(!mp[s[K]] && s[K]!='a'){
				v.push_back(s[K]);
				mp[s[K]] = K+1;
			}
		}
		
		
		//int x = 0;
		char c = 'a';
		for(int K = 0; K < (int)v.size(); K++){
			if(v[K] <= c) continue;
			
			mid = min(v[K]-c, k);
			
			k -= mid;
			
			//cout << v[K] << ' ' << k <<  ' ' << mid << ' ' << c << "\n";
			
			for(int L = 0; L < n; L++){
				if(s[L] <= v[K] && s[L] >= v[K]-mid) s[L] = (v[K]-mid==c ? 'a' : v[K]-mid);
			}
			
			c = max(v[K], c);
			//x = mid;
			
			if(k == 0) break;
		}
		
		cout << s << "\n";
	}
	
	return 0;
}




















































