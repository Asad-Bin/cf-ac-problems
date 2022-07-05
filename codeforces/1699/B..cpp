// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int ara[55][55];

void print(int K, int L, int a[2][2])
{
	ara[K][L] = a[0][0];
	ara[K][L+1] = a[0][1];
	ara[K+1][L] = a[1][0];
	ara[K+1][L+1] = a[1][1];
}
int main()
{
	int a[2][2], b[2][2];
	a[0][1] = a[1][0] = b[0][0] = b[1][1] = 0;
	a[0][0] = a[1][1] = b[0][1] = b[1][0] = 1;
	
	int t, n, m;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		memset(ara, 0, sizeof ara);
		for(int K = 0; K < n; K += 2){
			for(int L = 0; L < m; L += 2){
				if((K/2+L/2)%2==0) print(K, L, a);
				else print(K, L, b);
			}
		}
		
		for(int K = 0; K < n; K++){
			for(int L = 0; L < m; L++) cout << ara[K][L] << ' ';
			cout << "\n";
		}
	}
	
	return 0;
}




















































