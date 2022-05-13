// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n, m;
	string s[5];
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		for(int K = 0; K < n; K++) cin  >> s[K];
		
		int i = 0, idx = -1, mn = m;
		for(int K = 0; K < n; K++){
			int cnt = 0;
			for(int L = 0; L < m; L++){
				if(s[K][L] == 'R') break;
				cnt++;
			}
			if(cnt == m && idx == -1){
				i++;
				continue;
			}
			
			if(cnt < mn){
				mn = cnt;
				idx = K;
			}
		}
		
		bool ok = 1;
		if(idx != i) ok = 0;
		
		i = 0;
		idx = -1;
		mn = n;
		for(int K = 0; K < m; K++){
			int cnt = 0;
			for(int L = 0; L < n; L++){
				if(s[L][K] == 'R') break;
				cnt++;
			}
			if(cnt == n && idx == -1){
				i++;
				continue;
			}
			
			if(cnt < mn){
				mn = cnt;
				idx = K;
			}
		}
		if(idx != i) ok = 0;
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}




















































