// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int MX = 1e5;
int ara[MX+5];
int main()
{
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		int cnt = 0;
		for(int K = 1; K <= n; K++){
			cin >> ara[K];
			if(ara[K] < 0){
				cnt++;
				ara[K] *= -1;
			}
		}
		
		bool ok = 1;
		for(int K = 2; ok && K <= cnt; K++){
			if(ara[K-1] < ara[K]) ok = 0;
		}
		for(int K = cnt+2; ok && K <= n; K++){
			if(ara[K-1] > ara[K]) ok = 0;
		}
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}




















































