// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MXI = 1e9+7;
int main()
{
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		int ara[n];
		
		bool ok = 0;
		if(n%2==0) ok = 1;
		
		int a = MXI, b = MXI, i = n, j = n;
		for(int K = 0; K < n; K++){
			cin >> ara[K];
		}
		
		for(int K = 0; K < n; K++){
			if(K%2 == 1 && ara[K-1] > ara[K]){
				if(a > ara[K]){
					a = ara[K];
					i = K;
				}
				//else if(a == ara[K]){
					//i = min(i, K);
				//}
			}
			if(K%2==1){
				if(b > ara[K-1]){
					b = ara[K-1];
					j = K-1;
				}
				//else if(b == ara[K-1]){
					//j = min(j, K-1);
				//}
			}
			//if(K%2==1 && ara[K] == ara[K-1]){
				//if(c > ara[K-1]){
					//c = ara[K-1];
					//k = K-1;
				//}
			//}
		}
		//cout << a << ' ' << b << ' ' << i << ' ' << j << ' ' << "\n";
		if(a < b) ok = 0;
		else if(a == b){
			if(i < j) ok = 0;
		}
		
		if(!ok) cout << "Mike\n";
		else cout << "Joe\n";
	}
	
	return 0;
}




















































