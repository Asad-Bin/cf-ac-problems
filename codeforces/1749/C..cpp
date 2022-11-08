// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int ara[n], v[n];
		for(int K = 0; K < n; K++) cin >> ara[K], v[K] = ara[K];
		
		sort(v, v+n);
		
		int l = 1, r = n, sz = n;
		int ans = 0;
		while(l <= r){
			int mid = (l + r)/2;
			
			n = sz;
			for(int K = 0; K < n; K++) ara[K] = v[K];
			
			bool ok = 1;
			
			for(int K = 1; K <= mid; K++){
				ok = 0;
				
				//debug(mid) debug(K);
				//for(int L = 0; L < n; L++) cout << ara[L] << ' ';
				//cout << "\n";
				
				for(int L = n-1; L >= 0; L--){
					if(ara[L] <= mid-K+1){
						for(int M = L+1; M < n; M++) ara[M-1] = ara[M];
						ok = 1;
						break;
					}
				}
				
				if(!ok) break;
				
				n--;
				for(int L = 0; L < n; L++){
					if(ara[L]+mid-K+1 >= mid-K){
						ara[L] += mid-K+1;
						
						for(int M = L+1; M < n; M++) if(ara[M] < ara[M-1]) swap(ara[M], ara[M-1]);
						
						break;
					}
				}
			}
			
			if(ok){
				ans = max(ans, mid);
				l = mid+1;
			}
			else {
				r = mid-1;
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}





































