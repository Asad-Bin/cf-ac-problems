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
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		cout << 1 << ' ';
		for (int K = n; K >= 2; K--) cout << K << ' ';
		cout << "\n";
	}
	
	return 0;
}


























