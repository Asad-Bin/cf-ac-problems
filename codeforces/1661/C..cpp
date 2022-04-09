// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<long long>
#define PB push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
//#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


const int MX = 3e5;
int ara[MX+5], fix[MX+5];
int main()
{
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		int mx = 0;
		for(int K = 0; K < n; K++){
			cin >> ara[K];
			fix[K] = ara[K];
			mx = max(mx, ara[K]);
		}
		
		long long odd = 0, even = 0;
		for(int K = 0; K < n; K++){
			if((ara[K]&1) != (mx&1)){
				ara[K]++;
				odd++;
			}
		}
		
		for(int K = 0; K < n; K++) even += (mx-ara[K])/2;
		long long mid = (even-odd-3)/3;
		mid--;
		mid = max(mid, 0LL);
		odd += mid*2;
		even -= mid;
		while(odd+2 <= even){
			odd += 2;
			even--;
		}
		
		long long ans = max((odd-1)*2+1, even*2);
		
		// step 2
		for(int K = 0; K < n; K++) ara[K] = fix[K];
		
		mx++;
		odd = 0, even = 0;
		for(int K = 0; K < n; K++){
			if((ara[K]&1) != (mx&1)){
				ara[K]++;
				odd++;
			}
		}
		
		for(int K = 0; K < n; K++) even += (mx-ara[K])/2;
		mid = (even-odd-3)/3;
		mid--;
		mid = max(mid, 0LL);
		odd += mid*2;
		even -= mid;
		while(odd+2 <= even){
			odd += 2;
			even--;
		}
		ans = min(ans, max((odd-1)*2+1, even*2));
		
		// step 3
		for(int K = 0; K < n; K++) ara[K] = fix[K];
		
		mx++;
		odd = 0, even = 0;
		for(int K = 0; K < n; K++){
			if((ara[K]&1) != (mx&1)){
				ara[K]++;
				odd++;
			}
		}
		
		for(int K = 0; K < n; K++) even += (mx-ara[K])/2;
		mid = (even-odd-3)/3;
		mid--;
		mid = max(mid, 0LL);
		odd += mid*2;
		even -= mid;
		while(odd+2 <= even){
			odd += 2;
			even--;
		}
		ans = min(ans, max((odd-1)*2+1, even*2));
		
		
		// step 4
		
		for(int K = 0; K < n; K++) ara[K] = fix[K];
		
		mx++;
		odd = 0, even = 0;
		for(int K = 0; K < n; K++){
			if((ara[K]&1) != (mx&1)){
				ara[K]++;
				odd++;
			}
		}
		
		for(int K = 0; K < n; K++) even += (mx-ara[K])/2;
		mid = (even-odd-3)/3;
		mid--;
		mid = max(mid, 0LL);
		odd += mid*2;
		even -= mid;
		while(odd+2 <= even){
			odd += 2;
			even--;
		}
		ans = min(ans, max((odd-1)*2+1, even*2));
		
		
		cout << ans << "\n";
	}
	
	return 0;
}




















































