/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


string s, t;
bool vis[105][10][2];
bool calc(int at, int sum, int on, int n)
{
	//cout << at << ' ' << on << ' ' << sum << "\n";
	if(on && sum == 0) return 1;
	if(at == n) return 0;
	
	if(vis[at][sum][on]) return false;
	
	vis[at][sum][on] = 1;
	
	bool ok = 0; 
	
	ok |= calc(at+1, (sum*10+(s[at]-'0'))%8, 1, n);
	if(ok){
		t += s[at];
		return true;
	}
	
	ok |= calc(at+1, sum, on, n);
	if(ok){
		//t += s[at];
		return true;
	}
	
	return ok;
}
int main()
{
	cin >> s;
	
	t = "";
	if(calc(0, 0, 0, (int)s.length())){
		cout << "YES\n";
		
		reverse(t.begin(), t.end());
		cout << t << "\n";
	}
	else{
		cout << "NO\n";
	}
	
	return 0;
}
