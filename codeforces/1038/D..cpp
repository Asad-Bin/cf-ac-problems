// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x)        cerr << #x << " == " << (x) << '\n';


int main()
{
	int n;
	
	cin >> n;
	
	if(n == 1){
		cin >> n;
		
		cout << n << "\n";
		
		return 0;
	}
	
	ll ara[n];
	ll a = 0, b = 0, mn = 1e15+7;
	
	for(int K = 0; K < n; K++){
		cin >> ara[K];
		
		if(ara[K] > 0) a += ara[K];
		else b -= ara[K];
		
		mn = min(mn, abs(ara[K]));
	}
	
	//debug(a);
	//debug(b);
	//debug(mxp);
	//debug(mxn);
	
	if(a && b) cout << a+b << "\n";
	else cout << a+b-2*mn << "\n";
	
	return 0;
}




















































