// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, n;
	string s;
	
	cin >> t;
	while(t--){
		cin >> s;
		
		n = (int)s.length();
		
		int i = 0, j = n-1;
		for(int K = 0; K < n; K++){
			if(s[K] == '1') i = K;
			if(s[K] == '0'){
				j = K;
				break;
			}
		}
		
		cout << j-i+1 << "\n";
	}
	
	return 0;
}




















































