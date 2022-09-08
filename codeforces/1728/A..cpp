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
		
		int ans = 1, x = 0, mx = 0;
		for(int K = 1; K <= n; K++){
			cin >> x;
			if(x > mx){
				mx = x;
				ans = K;
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}

