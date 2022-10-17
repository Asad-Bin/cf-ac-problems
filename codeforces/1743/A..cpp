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



ll ncr(ll a , ll b){
	return a*(a-1)/2;
}
int main() 
{
	ll t, n, x;
	
	cin>> t;
	while(t--){
		cin >> n;
		for(int K = 1; K <= n;K++) cin >> x;
		
		cout << (ll)ncr(10-n, 2)*6 << "\n";
	}
	
	return 0;
}


























