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
		
		
		int i = 0, cnt = 0, ans = 0, sz = 0, ok = 0;
		char c = s[0];
		
		while(i < n){
			if(s[i] == c){
				cnt++;
			}
			else{
				if(cnt&1){
					if(ok){
						if(cnt <= 2) sz -= 3;
						ok = 0;
						//ans++;
					}
					else{
						ok = cnt;
					}
				}
				
				c = s[i];
				cnt = 1;
				sz++;
				if(ok) ans++;
			}
			
			//cout << i << ' ' << c << ' ' << cnt << ' ' << ans << ' ' << sz << "\n";
			i++;
		}
		if(cnt&1){
			if(ok){
				if(cnt <= 2) sz--;
				ok = 0;
				//ans++;
			}
			else{
				ok = cnt;
			}
			
			if(ok) ans++;
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































