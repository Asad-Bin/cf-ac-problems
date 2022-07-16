// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n;
	//map<int, int> mp;
	vector<int> v;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		int ara[n];
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		int x = 0;
		while(true){
			//mp.clear();
			v.clear();
			if(x){
				v.push_back(ara[0]);
				x--;
			}
			
			for(int K = 1; K < n; K++){
				if(ara[K] == ara[K-1]){
					x++;
					continue;
				}
				
				v.push_back(ara[K]-ara[K-1]);
			}
			
			//for(auto x:mp) v.push_back(x.first);
			sort(v.begin(), v.end());
			
			n = (int)v.size();
			if(n == 1) break;
			if(n == 0){
				v.push_back(0);
				break;
			}
			
			//if(v[n-2] == 0) break;
			
			for(int K = 0; K < n; K++) ara[K] = v[K];
		}
		
		cout << v[0] << "\n";
	}
	
	return 0;
}




















































