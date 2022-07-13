// . . . Bismillahir Rahmanir Rahim . . . //

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MXI = 1e9;
const int MX = 2e5;
int a[MX+5], b[MX+5];

int main()
{
	int t, n;
	map<int, int> mp;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		mp.clear();
		for(int K = 0; K < n; K++){
			cin >> a[K];
			while(a[K]%2==0) a[K] /= 2;
			mp[a[K]]++;
		}
		for(int K = 0; K < n; K++) cin >> b[K];
		
		bool ok = 1;
		for(int K = n-1; K >= 0; K--){
			while(b[K] > 1 && mp[b[K]] == 0){
				b[K] /= 2;
			}
			
			if(b[K] == 1 && mp[1] == 0){
				ok = 0;
				break;
			}
			
			mp[b[K]]--;
		}
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}




















































