// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 2e5;
bool ara[MX+5];
int main()
{
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		for(int K = 1; K <= n; K++) ara[K] = 0;
		
		cout << 2 << "\n";
		for(int K = 1; K <= n; K++){
			if(ara[K]) continue;
			
			int x = K;
			while(x <= n){
				cout << x << ' ';
				ara[x] = 1;
				x *= 2;
			}
		}
		cout << "\n";
	}
	
	return 0;
}




















































