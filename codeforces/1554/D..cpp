// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--){
		int n;
		
		cin  >> n;
		
		string s = "";
		s.assign(n, 'a');
		
		s[n/2] = 'b';
		if(n%2==1) s[n/2+1] = 'c';
		
		cout << s << "\n";
	}
	
	return 0;
}





































