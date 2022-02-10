/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


int row[100], col[100];
int main()
{
	int t, n, m, a, b;
	
	cin >> t;
	while(t--){
		cin >> n >> m >> a >> b;
		
		if(n*a != m*b){
			cout << "NO\n";
			continue;
		}
		
		string s[n];
		
		int st = 0;
		
		for(int K = 0; K < n; K++){
			s[K].assign(m, '0');
			
			int num = a;
			if(true){
				for(int L = st; num>0; L = (L+1)%m, num--) s[K][L] = '1';
				st = (st+a)%m;
			}
			else{
				for(int L = st; L < m; L++) s[K][L] = '1';
				for(int L = 0; L < a-(m-st+1);L++) s[K][L] = '1';
				st = a-(m-st+1);
			}
		}
		
		memset(row, 0, sizeof row);
		memset(col, 0, sizeof col);
		bool ok = 1;
		for(int K = 0; K < n; K++){
			for(int L = 0; L < m; L++){
				if(s[K][L] == '1'){
					row[K]++;
					col[L]++;
					
					if(row[K] > a || col[L] > b) ok = 0;
				}
			}
		}
		
		if(ok){
			cout << "YES\n";
			for(int K = 0; K < n; K++) cout << s[K] << "\n";
		}
		else{
			cout << "NO\n";
		}
	}
	
	return 0;
}
