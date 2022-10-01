// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif



bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second-a.first > b.second-b.first;
}
bool cmp2(pair<int, int> a, pair<int, int> b)
{
	return a.first+a.second < b.first+b.second;
}
bool ccw (pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
	return a.first*(b.second-c.second) + b.first*(c.second-a.second) + c.first*(a.second-b.second) > 0 || a.first*(b.second-c.second) + b.first*(c.second-a.second) + c.first*(a.second-b.second) == 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		int a = 0;
		for(int K = 0; K < n; K++) {
			int x;cin >> x;
			if(x&1) a++;
		}
		
		if(a%4 == 2) cout << "Bob\n";
		else if(a%4 == 3) cout << "Alice\n";
		else if(a%4 == 0) cout << "Alice\n";
		else if((n-a)%2 == 1) cout << "Alice\n";
		else cout << "Bob\n";
	}
	
	
	return 0;
}





































