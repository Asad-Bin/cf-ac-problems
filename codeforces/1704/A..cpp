//. . .Bismillahir Rahmanir Rahim. . .
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x)        cerr << #x << " == " << (x) << '\n';


int main()
{
	int t, n, m;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		string a, b;
		
		cin >> a >> b;
		
		bool ok = 1;
		int K, L;
		for(K = n-1, L = m-1; L >= 1; K--, L--){
			if(a[K] != b[L]){
				ok = 0;
				break;
			}
		}
		
		if(!ok){
			cout << "NO\n";
			continue;
		}
		
		ok = 0;
		for(; K >= 0; K--){
			if(a[K] == b[0]) ok = 1;
		}
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}























