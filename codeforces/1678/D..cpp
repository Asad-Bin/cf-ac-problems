// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 1e6;
int ro[MX+5];
int main()
{
	int t, n, m;
	string s;
	set<int> ss;
	
	cin >> t;
	while(t--){
		cin >> n >> m >> s;
		
		int x = -1e9-7;
		ss.clear();
		
		for(int K = 0; K < n*m; K++){
			ro[K] = 0;
			if(s[K] == '1'){
				ss.insert(K%m);
				x = K;
			}
			
			if(K >= m) ro[K] = ro[K-m];
			if(K-x < m) ro[K]++;
			
			cout << (int)ss.size()+ro[K] << ' ';
		}
		cout << "\n";
	}
	
	return 0;
}




















































