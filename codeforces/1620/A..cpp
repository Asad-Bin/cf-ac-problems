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
	
	int t; cin >>  t;
	while(t--){
		string s;
		cin >> s;
		
		int cnt = 0;
		for(int K = 0; K < (int)s.length(); K++){
			if(s[K] == 'N') cnt++;
		}
		
		if(cnt == 1){
			cout << "NO\n";
		}
		else cout << "YES\n";
		//if((int)s.length() == 2){
			//if(s[0] == s[1]) cout << "YES\n";
			//else cout << "NO\n";
		//}
		//else cout << "YES\n";
	}
	
	return 0;
}





































