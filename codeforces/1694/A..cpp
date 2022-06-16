// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t, a, b;
	
	cin >> t;
	while(t--){
		cin >> a >> b;
		
		string s = "";
		
		if(a >= b){
			int mid = a/b, cnt = a%b;
			
			while(a || b){
				if(b){
					s += "1";
					b--;
				}
				for(int K = 0; a && K < mid; K++){
					s += "0";
					a--;
				}
				if(cnt){
					s += "0";
					cnt--;
					a--;
				}
			}
		}
		else{
			swap(a, b);
			
			int mid = a/b, cnt = a%b;
			
			while(a || b){
				if(b){
					s += "0";
					b--;
				}
				for(int K = 0; a && K < mid; K++){
					s += "1";
					a--;
				}
				if(cnt){
					s += "1";
					cnt--;
					a--;
				}
			}
		}
		
		cout << s << "\n";
	}
	
	return 0;
}




















































