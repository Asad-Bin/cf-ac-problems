/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;

const int MX = 5e5;
vector<int> v(MX+5), ara[MX+5];

int main()
{
	int q;
	
	cin >> q;
	vector<int> t(q+1), x(q+1), y(q+1);
	
	for(int K = 1; K <= q; K++){
		cin >> t[K] >> x[K];
		
		if(t[K] == 2) cin >> y[K];
	}
	
	vector<int> p(MX+1), ans;
	iota(p.begin(), p.end(), 0);
	
	
	for(int K = q; K >= 1; K--){
		if(t[K] == 1){
			ans.push_back(p[x[K]]);
		}
		else{
			p[x[K]] = p[y[K]];
		}
	}
	
	reverse(ans.begin(), ans.end());
	for(auto it:ans) cout << it << ' ';
	cout << "\n";
	
	return 0;
}
