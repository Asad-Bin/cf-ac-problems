// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x)        cerr << #x << " == " << (x) << '\n';


int main()
{
	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		string a, b;
		cin >> a >> b;
		
		vector<int> ans;
		for(int K = 0; K < n-1;  K++){
			if(a[K] != a[K+1]) ans.push_back(K+1);
		}
		if(a[n-1] == '1') ans.push_back(n);
		
		for(int K = n-1; K >= 0; K--){
			if((K == n-1 && b[K] == '1') || (K < n-1 && b[K] != b[K+1])) ans.push_back(K+1);
		}
		
		cout << (int)ans.size() << " ";
		for(auto x:ans) cout << x << ' ';
		cout << "\n";
	}
	
	return 0;
}





















































