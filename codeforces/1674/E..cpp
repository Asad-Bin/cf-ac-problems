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


int main()
{
	int n;
	
	cin >> n;
	
	int ara[n];
	for(int K = 0; K < n; K++) cin >> ara[K];
	
	int ans[3];
	ans[0] = ans[1] = ans[2] = 1000*1000+5;
	
	int mn_1 = 1000*1000+5, mn_2 = 1000*1000+5;
	for(int K = 0; K < n; K++){
		if(ara[K] <= mn_1){
			mn_2 = mn_1;
			mn_1 = ara[K];
		}
		else if(ara[K] <= mn_2){
			mn_2 = ara[K];
		}
	}
	ans[0] = (mn_1+1)/2+(mn_2+1)/2;
	
	
	for(int K = 1; K < n-1; K++){
		ans[2] = min(ans[2], min(ara[K-1], ara[K+1])+(abs(ara[K-1]-ara[K+1])+1)/2);
	}
	
	int x;
	for(int K = 0; K+1 < n; K++){
		int a = ara[K];
		int b = ara[K+1];
		
		if(a < b) swap(a, b);
		
		if(a >= 2*b) x = (a+1)/2;
		else x = (a+b+2)/3;
		
		ans[1] = min(ans[1], x);
	}
	
	//cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << "\n";
	cout << min({ans[0], ans[1], ans[2]}) << "\n";
	
	return 0;
}




















































