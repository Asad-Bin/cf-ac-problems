/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


const int MX = 1e5;
int ara[MX+5], cop[MX+5];
int main()
{
	int t, n, k;
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int K = 1; K <= n; K++) cin >> ara[K];
		for(int K = 1; K <= n; K++) cop[K] = (ara[K] == k ? 1 : (ara[K] > k ? 2 : 0));
		
		//vector<int> v;
		//for(int K = (n+1)/2-1; K >= 1; K--){
			//v.clear();
			//v.push_back(cop[K]);
			//v.push_back(cop[K+1]);
			//v.push_back(cop[K+2]);
			//sort(v.begin(), v.end());
			
			//if((v[0] == 0 || v[0] == 1) && !v[1] == 0) cop[K] = cop[K+1] = cop[K+2] = v[1];
			
			////if(cop[K] == 0 && cop[K+1] > 0 && cop[K+2] > 0) cop[K] = min(cop[K+1], cop[K+2]);
		//}
		//for(int K = (n+1)/2+1; K <= n; K++){
			//v.clear();
			//v.push_back(cop[K]);
			//v.push_back(cop[K-1]);
			//v.push_back(cop[K-2]);
			//sort(v.begin(), v.end());
			
			//if((v[0] == 0 || v[0] == 1) && !v[1] == 0) cop[K] = cop[K-1] = cop[K-2] = v[1];
			
			////if(cop[K] == 0 && cop[K-1] > 0 && cop[K-2] > 0) cop[K] = min(cop[K-1], cop[K-2]);
		//}
		
		//for(int K = 1; K <= n; K++) cout << cop[K] << ' ';
		//cout << "\n";
		
		bool ok = 0;
		
		for(int K = 1; K <= n; K++) if(ara[K] == k) ok = 1;
		if(!ok){
			cout << "no\n";
			continue;
		}
		if(n == 1){
			if(k == ara[1]) cout << "yes\n";
			else cout << "no\n";
			continue; 
		}
		ok = 0;
		for(int K = 1; K < n; K++) if(cop[K] >= 1 && cop[K+1] >= 1) ok = 1;
		for(int K = 1; K < n-1; K++) if(cop[K] >= 1 && cop[K+2] >= 1) ok = 1; 
		
		//for(int K = 1; K < (n+1)/2; K++){
			//if(cop[K] && !cop[K+1]) ok = 0;
		//} 
		
		//if(ok){
			////cout << "hi\n";
			//cout << "yes\n";
			//continue;
		//}
		
		//for(int K = n; K >(n+1)/2; K--){
			//if(cop[K] && !cop[K-1]) ok = 0;
		//}
		
		if(ok){
			cout << "yes\n";
			continue;
		}
		
		cout << "no\n";
		
		
		//sort(cop+1, cop+n+1);
		
		//int pos = (n+1)/2;
		
		//int num = cop[pos];
		//for(int K = 1; K <= n; K++) if(ara[K] == )
		
		//bool ok = 0;
		//for(int K = 1; K <= n; K++){
			//if(K <= (n+1)/2 && ara[K] == k){
				//int i = K-1;
				//int j = pos-K;
				
				//if(i < j) continue;
				
				//ok = 1;
				//break;
			//}
			//else if(K > (n+1)/2 && ara[K] == k){
				//int i = K-pos+1;
				//int j = n-K;
				
				//if(i > j) continue;
				
				//ok = 1;
				//break;
			//}
		//}
		
		//if(ok) cout << "yes\n";
		//else cout << "no\n";
	}
	
	return 0;
}
