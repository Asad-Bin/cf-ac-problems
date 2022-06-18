// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MXI = 1e9;
int main()
{
	int t, n, m;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		int ara[n][m];
		int mx = -MXI-7, i = -1, j = -1;
		for(int K = 0; K < n; K++){
			for(int L = 0; L < m; L++){
				cin >> ara[K][L];
				if(ara[K][L] > mx){
					mx = ara[K][L];
					i = K;
					j = L;
				}
			}
		}
		i++;
		j++;
		
		cout << max(i, n-i+1)*max(j, m-j+1) << "\n";
	}
	
	return 0;
}




















































