//. . .Bismillahir Rahmanir Rahim. . .
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x)        cerr << #x << " == " << (x) << '\n';


int main()
{
	int t, n, x;
	
	cin >> t;
	while(t--){
		cin >> n >> x;
		
		int ans = 0;
		set<int> ss;
		for(int K = 0; K < n; K++){
			int num;
			
			cin >> num;
			
			ss.insert(num);
			
			if(*ss.rbegin()-*ss.begin() > 2*x){
				ss.clear();
				ans++;
				ss.insert(num);
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}























