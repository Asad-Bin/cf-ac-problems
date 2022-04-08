/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;

const int MX = 5e5;
vector<int> v(MX+5), ara[MX+5];

int main()
{
	int q, t, x, y, i = 0;
	
	cin >> q;
	while(q--){
		cin >> t;
		
		if(t == 1){
			cin >> v[i];
			
			ara[v[i]].push_back(i);
			i++;
		}
		else{
			cin >> x >> y;
			
			if(x != y){
				if(ara[x].size() > ara[y].size()) ara[x].swap(ara[y]);
				
				for(int K = 0; K < (int)ara[x].size(); K++) ara[y].push_back(ara[x][K]);
				ara[x].clear();
			}
		}
		//cout << i << "\n";
	}
	
	for(int K = 1; K <= MX; K++){
		for(int L = 0; L < (int)ara[K].size(); L++){
			v[ara[K][L]] = K;
		}
	}
	
	for(int K = 0; K < i; K++) cout << v[K] << ' ' ;
	cout << "\n";
	
	return 0;
}
