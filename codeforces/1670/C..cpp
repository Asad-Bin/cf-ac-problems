// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 1e5;
int a[MX+5], b[MX+5], c[MX+5];
int pos_a[MX+5], pos_b[MX+5], pos_c[MX+5];
bool mark[MX+5];

const ll mod = 1e9+7;

bool f = 0;
void call(int K)
{
	if(mark[K]) return;
	
	if(pos_c[K]) f = 1;
	mark[K] = 1;
	call(b[pos_a[K]]);
	call(a[pos_b[K]]);
}
int main()
{
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		for(int K = 1; K <= n; K++){
			cin >> a[K];
			pos_a[a[K]] = K;
		}
		for(int K = 1; K <= n; K++){
			cin >> b[K];
			pos_b[b[K]] = K;
		}
		
		for(int K = 1; K <= n; K++) pos_c[K] = mark[K] = 0;
		for(int K = 1; K <= n; K++){
			cin >> c[K];
			pos_c[c[K]] = K;
		}
		
		int cnt = 0;
		for(int K = 1; K <= n; K++){
			if(pos_a[K] == pos_b[K]){
				c[pos_a[K]] = K;
				mark[K] = 1;
			}
			else if(!mark[K]){
				f = 0;
				
				if(pos_c[K]) f = 1;
				mark[K] = 1;
				call(b[pos_a[K]]);
				call(a[pos_b[K]]);
				
				if(!f) cnt++;
			}
		}
		
		ll ans = 1;
		while(cnt--) ans = (ans*2LL)%mod;
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































