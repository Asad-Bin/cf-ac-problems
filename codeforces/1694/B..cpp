// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n;
	string s;
	vector<vector<int> > v;
	
	cin >> t;
	while(t--){
		cin >> n >> s;
		
		v.clear();
		for(int K = 0; K < n; K++){
			int cnt = 0;
			for(int L = K; L < n; L++){
				if(s[K] != s[L]) break;
				cnt++;
			}
			v.push_back(vector<int>{K, K+cnt-1, cnt});
			K += cnt-1;
		}
		
		ll ans = 0;
		for(int K = (int)v.size()-1; K >= 0; K--){
			ans += v[K][0]+1;
			ans += v[K][2]-1;
			//cout << K << ' ' << v[K][0] << ' ' << v[K][1] << ' ' << v[K][2] << "\n";
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































