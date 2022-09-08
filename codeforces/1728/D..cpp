// Create your own template by modifying this file!
#include <bits/stdc++.h>
using namespace std;

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



int t, n;
string s;
// 0 for draw
// -1 for bob
// 1 for alice
const int N = 2000;
int dp[N+5][N+5];

int calc(int i, int j)
{
	if(i+1 == j){
		//cout << i << ' ' << j << ' ' << s[i] << ' ' << s[j] << "\n";
		if(s[i] == s[j]) return 0;
		return 1;
	}
	
	if(dp[i][j] != -5) return dp[i][j];
	
	int ans = 0;
	
	int x = calc(i+2, j);
	if(x == 0){
		if(s[i] == s[i+1]) {}
		else if(s[i] < s[i+1]) x = 1;
		else x = -1;
	}
	int y = calc(i+1, j-1);
	if(y == 0){
		if(s[i] == s[j]) {}
		else if(s[i] < s[j]) y = 1;
		else y = -1;
	}
	
	ans = min(x, y);
	//if(x != 1 || y != 1) 
	//else ans = 1;//return dp[i][j] = ans = 1;
	
	x = calc(i, j-2);
	if(x == 0){
		if(s[j-1] == s[j]) {}
		else if(s[j-1] > s[j]) x = 1;
		else x = -1;
	}
	y = calc(i+1, j-1);
	if(y == 0){
		if(s[i] == s[j]) {}
		else if(s[i] > s[j]) y = 1;
		else y = -1;
	}
	
	ans = max(ans, min(x, y));
	//if(x != 1 || y != 1) 
	//else ans = 1;
	
	
	//if(x <= 0){
		//x = calc(i+1, j-1);
		//if(x == 0){
			//if(s[i] == s[j]) {}
			//else if(s[i] < s[j]) x = 1;
			//else x = -1;
		//}
		
		//if(x <= 0){
			//x = calc(i+1, j-1);
			//if(x == 0){
				//if(s[i] == s[j]) {}
				//else if(s[i] > s[j]) x = 1;
				//else x = -1;
			//}
			
			//if(x <= 0){
				//x = calc(i, j-2);
				//if(x == 0){
					//if(s[j-1] == s[j]) {}
					//else if(s[j-1] > s[j]) x = 1;
					//else x = -1;
				//}
			//}
		//}
	//}
	
	//cout << i << ' ' << j << ' ' << ans << "\n";
	return dp[i][j] = ans;
}

int main() 
{
	cin >> t;
	while(t--){
		cin >> s;
		n = (int)s.length();
		
		for(int K = 0; K <= n; K++){
			for(int L = 0; L <= n; L++) dp[K][L] = -5;
		}
		int ans = calc(0, n-1);
		
		if(ans == -1) cout << "Bob\n";
		else if(ans == 0) cout << "Draw\n";
		else cout << "Alice\n";
	}
	
	return 0;
}

