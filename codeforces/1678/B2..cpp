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
		cin >> n >> s;
		
		
		int op = 0, seg = 0, p = -1;
		
		for(int K = 0; K < n; K+=2){
			if(s[K] != s[K+1]){
				op++;
			}
			else{
				if(p != s[K]) seg++;
				p = s[K];
			}
		}
		cout << op << ' ' << max(seg, 1) << "\n";
	}
	
	return 0;
}




















































