// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n, k, x, a, b;
	map<int, vector<int> > v;
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		
		v.clear();
		for(int K = 0; K < n; K++){
			cin >> x;
			v[x].push_back(K);
		}
		
		while(k--){
			cin >> a >> b;
			
			if(!v[a].empty() && !v[b].empty() && v[a][0] < v[b].back()) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	
	return 0;
}




















































