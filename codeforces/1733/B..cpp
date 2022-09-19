// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int n, x, y, t;
	
	cin >> t;
	while(t--){
		cin >> n >> x >> y;
		
		if(x < y ) swap(x, y);
		
		if(x && y) cout << -1 << endl;
		else if(!x && !y) cout << -1 << endl;
		else if((n-1)%x != 0) cout << -1 << endl; 
		else{
			int i = 1;
			for(int K = 1; K < n; K++){
				//ara[K] = i;
				cout << i << ' ';
				
				if(K%x == 0){
					i = K + 2;
				}
			}
			
			cout << endl;
		}
	}
	
	return 0;
}




















































