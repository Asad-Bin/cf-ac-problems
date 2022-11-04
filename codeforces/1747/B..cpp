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
		
		if(n ==1 ){
			cout << 1 << "\n" << 1 << ' ' << 2 << "\n";
			continue;
		}
		
		if(n%2==0){
			cout << n/2 << "\n";
			n *= 3;
			for(int K = 1; K <= n/ 2; K+=3) cout << K << ' ' << n-K+1 << "\n";
		}
		else{
			cout << n/2+1 << "\n";
			n *= 3;
			for(int K = 1; K <= n/2; K+=3 ) cout << K << ' ' << n-K+1 << "\n";
		}
	}
	
	return 0;
}


























