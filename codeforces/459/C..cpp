/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;

const int MX = 1000;
vector<vector<int> > ara(MX+5, vector<int> (MX+5));

int main()
{
	int n, k, d;
	
	cin >> n >> k >> d;
	
	bool ok = 0;
	long long x = 1;
	for(int K = 0; K < d; K++){
		x *= k;
		if(x >= n){
			ok = 1;
			break;
		}
	}
	if(!ok){
		cout << "-1\n";
		return 0;
	}
	
	for(int K = 1; K < n; K++){
		for(int L = 0; L < d; L++) ara[K][L] = ara[K-1][L];
		for(int L = d-1; L >= 0; L--){
			ara[K][L] = (ara[K][L]+1)%k;
			if(ara[K][L]) break;
		}
	}
	
	for(int K = 0; K < d; K++){
		for(int L = 0; L < n; L++) cout << ara[L][K] + 1 << " ";
		cout << "\n";
	}
	
	
	
	return 0;
}
