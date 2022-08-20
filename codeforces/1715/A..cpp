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
	ll t, n, m;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		cout << n+m-2 + (max(n, m) > 1 ? 1 : 0) +min(n, m)-1 << "\n";
	}
	
	return 0;
}

