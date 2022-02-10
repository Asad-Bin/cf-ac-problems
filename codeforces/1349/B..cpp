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
    		
    		if(ok){
    			cout << "yes\n";
    			continue;
    		}
    		
    		cout << "no\n";
    	}
    	
    	return 0;
    }
