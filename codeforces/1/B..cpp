/**
 * Bismillahir Rahmanir Rahim
**/

#include <bits/stdc++.h>

using namespace std;


void khela1(string& s)
{
	int n = (int)s.length();
	
	int x = 0, y = 0;
	for(int K = 1; K < n; K++){
		if(s[K] == 'C'){
			for(int L = K+1; L < n; L++){
				y = y*10 + (s[L]-'0');
			}
			
			break;
		}
		x = x*10+(s[K]-'0');
	}
	
		s = ((y%26 ? y%26 : 26)+'A'-1);
		y -= ((y%26 ? y%26 : 26));
		y /= 26;
	while(y){
		s += ((y%26 ? y%26 : 26)+'A'-1);
		y -= (y%26 ? y%26 : 26);
		y /= 26;
		//int mid = y%26;
		//cout << y << ' ' << mid << "\n";
		
		//y /= 26;
		////if(mid == 0) mid = 26;
		
		//s += 'A'+mid-1;
	}
	reverse(s.begin(), s.end());
	cout << s << x << "\n";
}
void khela2(string& s)
{
	int n = (int)s.length();
	
	int x = 0, y = 0;
	
	for(int K = 0; K < n; K++){
		if(s[K] >= '0' && s[K] <= '9'){
			for(int L = K; L < n; L++){
				y = y*10 + (s[L]-'0');
			}
			
			break;
		}
		
		x = x*26+(s[K]-'A'+1);
	}
	
	cout << 'R' << y << 'C' << x << "\n";
}
int main()
{
	string s;
	
	int n;
	cin >> n;
	
	while(n--){
		cin >> s;
		
		bool ok = 0;
		for(int K = 0; K < (int)s.length(); K++){
			if(s[K] >= '0' && s[K] <= '9'){
				for(int L = K+1; L < (int)s.length(); L++){
					if(s[L] >= 'A' && s[L] <= 'Z'){
						ok = 1;
						break;
					}
				}
			
				break;
			}
		}
		
		if(ok) khela1(s);
		else khela2(s);
	}
	
	return 0;
}
