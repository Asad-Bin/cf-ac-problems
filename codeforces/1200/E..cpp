// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif


const ll mod1 = 1e9+7;
const ll mod2 = 1e9+9;
const ll base = 79;

int main()
{
	int n;
	
	cin >> n;
	
	string s[n];
	for(int K = 0; K < n; K++) cin >> s[K];
	
	string ans = s[0];
	int len = s[0].length();
	
	for(int K = 1; K < n; K++){
		int m = (int)s[K].length(), i = len-1;
		
		ll x1 = 0, y1 = 0, i1 = 1, x2 = 0, y2 = 0, i2 = 1;
		ll rec = -1;
		
		for(int L = 0; L < m; L++){
			if(i == -1){
				//rec = max(-1LL, rec);
				break;
			}
			
			x1 = x1 + ((s[K][L]-'0'+1)*i1%mod1);
			x1 %= mod1;
			
			x2 = x2 + ((s[K][L]-'0'+1)*i2%mod2);
			x2 %= mod2;
			
			y1 = (y1*base%mod1) + (ans[i]-'0'+1);
			y1 %= mod1;
			
			y2 = (y2*base%mod2) + (ans[i]-'0'+1);
			y2 %= mod2;
			
			//cout << K << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << "\n";
			if(x1 == y1 && x2 == y2){
				rec = L;
			}
			
			i1 = i1*base%mod1;
			i2 = i2*base%mod2;
			i--;
		}
		
		for(int L = rec+1; L < m; L++) ans += s[K][L], len++;
	}
	
	cout << ans << "\n";
	
	
	return 0;
}
