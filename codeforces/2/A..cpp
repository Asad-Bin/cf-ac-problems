/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;



int main()
{
	int n, x;
	string s;
	vector<string> sol;
	vector<pair<string, int> > v;
	map<string, int> mp;
	
	cin >> n;
	
	for(int K = 0; K < n; K++){
		cin >> s >> x;
		
		mp[s] += x;
		v.push_back({s, mp[s]});
		//cout << K << ' ' << s << ' ' << x << ' ' << mp[s] << "\n";
	}
	
	int mx = 0;
	for(auto it:mp){
		if(it.second > mx){
			sol.clear();
			mx = it.second;
			sol.push_back(it.first);
		}
		else if(it.second == mx){
			sol.push_back(it.first);
		}
	}
	
	int mn = 1000;
	s = "";
	for(int K = 0; K < (int)sol.size(); K++){
		for(int L = 0; L < n; L++){
			if(v[L].second >= mx && v[L].first == sol[K]){
				if(L < mn){
					//cout << sol[K] << ' ' << v[L] << ' ' << L << ' ' << mn << ' ' << mp[v[L]] << "\n";
					mn = L;
					s = v[L].first;
				}
				
				break;
			} 
		}
	}
	cout << s << "\n";
	
	
	return 0;
}
