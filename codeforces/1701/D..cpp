// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		int a[n+1], b[n+1] = {0};
		for(int K = 1; K <= n; K++) cin >> b[K];
		for(int K = 1; K <= n; K++) a[K] = -1;
		vector<vector<pair<int, int> > > v(n+1);
		
		for(int K = 1; K <= n; K++){
			// Finding the range of value for a[] for which b[] is correct . . . 
			// as for b[K] = 0, any value greater than K is valid.
			int x = K+1, y = n;
			if(b[K] != 0){
				x = K/(b[K]+1)+1;
				y = K/b[K];
			}
			
			// all y's are candidate for position x;
			// but for multiple candidate, we need candidate with priorities . . .
			// the lesser value of y the more prior it will be proccessed
			v[x].push_back({y, K});
		}
		
		set<pair<int, int> > ss;
		for(int K = 1; K <= n; K++){
			for(int L = 0; L < (int)v[K].size(); L++) ss.insert(v[K][L]);
			
			pair<int, int> x = *ss.begin();
			ss.erase(x);
			a[x.second] = K;
		}
		
		for(int K = 1; K <= n; K++) cout << a[K] << ' ';
		cout << "\n";
	}
	
	return 0;
}




















































