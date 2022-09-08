// Create your own template by modifying this file!
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

int main() 
{
	int t, n;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		
		int ara[n+1];
		
		if(n%2==0){
			for(int K = 1, L = n-2; L >= 1; L--, K++) ara[K] = L;
			ara[n-1] = n-1;
			ara[n] = n;
		}
		else{
			ara[1] = 1;
			for(int K = 2, L = n-2; L >= 2; L--, K++) ara[K] = L;
			ara[n-1] = n-1;
			ara[n] = n;
		}
		
		for(int K = 1; K <= n; K++) cout << ara[K] << ' ';
		cout << "\n";
	}
	
	return 0;
}

