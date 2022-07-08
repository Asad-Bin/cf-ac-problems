// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t;
	int ara[2][2];
	
	cin >> t;
	while(t--){
		cin >> ara[0][0]  >> ara[0][1];
		cin >> ara[1][0] >> ara[1][1];
		
		if(ara[0][0] || ara[0][1] || ara[1][0] || ara[1][1]){
			if(ara[0][0] && ara[0][1] && ara[1][0] && ara[1][1]) cout << 2 << "\n";
			else cout << 1 << "\n";
		}
		else{
			cout << 0 << "\n";
		}
	}
	
	return 0;
}




















































