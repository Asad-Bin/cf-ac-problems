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


const int MX = 2e5;
int a[MX+5], c[MX+5];
int main()
{
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		memset(a, 0, sizeof a);
		for(int K = 1; K <= n; K++) cin >> c[K];
		deque<int> v;
		
		if(c[1]) a[1] = 1;
		else a[1] = 0;
		v.push_back((a[1] ? c[1]+1 : 1+c[1]));
		
		for(int K = 1; K <= n; K++){
			while(!v.empty() && v.front() < K) v.pop_front();
			
			//for(auto x:v) cout << x << ' ';
			//cout << "\n";
			
			if(!v.empty() && v.front()==K) a[K] = 0;
			else if(v.empty() && c[K]==0) a[K] = 0;
			else a[K] = 1;
			
			//v.pop_front();
			v.push_back((a[K] ? c[K]+1 : K+c[K]));
			//cout << K << ' ' << a[K] << ' ' << c[K] << ' ' << (a[K] ? c[K]+1 : K+c[K]) << "\n";
		}
		
		for(int K = 1; K <= n; K++) cout << a[K] << ' ';
		cout << "\n";
	}
	
	return 0;
}




















































