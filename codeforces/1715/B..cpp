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
	ll t, n, k, b, s;
	vector<ll> v;
	
	cin >> t;
	while(t--){
		cin >> n >> k >> b >> s;
		
		v.clear();
		ll val = min(b*k+k-1, s);
		
		if(val < b*k){
			cout << -1 << "\n";
			continue;
		}
		
		v.push_back(val);
		s -= val;
		for(int K = 1; K < n; K++){
			val = min(k-1, s);
			v.push_back(val);
			s -= val;
		}
		
		if(s){
			cout << -1 << "\n";
			continue;
		}
		
		for(auto x:v) cout << x << ' ';
		cout << "\n";
	}
	
	return 0;
}


















