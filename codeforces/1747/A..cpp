// . . . Bismillahir Rahmanir Rahim . . .
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		
		int ara[n];
		
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		sort(ara, ara+n);
		
		ll a = 0;
		for(int K = 0; K < n; K++){
			if(ara[K] >= 0) break;
			
			a += ara[K];
		}
		a *= -1;
		
		ll b = 0;
		for(int K = 0; K < n; K++) if ( ara[K] >= 0) b += ara[K];
		
		cout << abs(a-b) << "\n";
	}
	
	return 0;
}


























