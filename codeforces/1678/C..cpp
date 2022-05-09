// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main()
{
	int t, n;
	indexed_set ss;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		int ara[n+2];
		for(int K = 1; K <= n; K++){
			cin >> ara[K];
		}
		
		ll ans = 0, cnt = 0, mid = 0;
		
		ss.clear();
		ss.insert(ara[n]);
		for(int K = n-1; K >= 1; K--){
			cnt = 0;
			for(int L = K-1; L >= 1; L--){
				if(ara[L] < ara[K]){
					ans += cnt;
				}
				
				mid = ss.order_of_key(ara[L]);
				cnt += mid;
			}
			ss.insert(ara[K]);
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































