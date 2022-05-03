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
	int n, m, q, a, b, x, y;
	int cnt = 0;
	
	cin >> n >> m >> q;
	
	string s[n];
	for(int K = 0; K < n; K++) cin >> s[K];
	
	for(int K = 0; K < n; K++){
		for(int L = 0; L < m; L++){
			if(s[K][L] == '*'){
				cnt++;
			}
		}
	}
	
	int ans, in = 0;
	a = b = -1;
	ans = cnt;
	//cout << cnt << "\n";
	
	for(int K = 0; K < m; K++){
		for(int L = 0; L < n; L++){
			if(cnt){
				cnt--;
				if(s[L][K] == '*') in++;
				
				a = L;
				b = K;
			}
			else break;
		}
	}
	//cout << a << ' ' << b << "\n";
	
	while(q--){
		cin >> x >> y;
		x--;
		y--;
		
		if(s[x][y] == '*'){
			b = ans/n;
			if(ans%n==0) b--;
			a = ans-(b*n)-1;
			
			if(s[a][b] == '*') in--;
			
			s[x][y] = '.';
			ans--;
			
			if(y*n+x+1 <= ans) in--;
		}
		else{
			ans++;
			
			b = ans/n;
			if(ans%n==0) b--;
			a = ans-(b*n)-1;
			
			if(s[a][b] == '*') in++;
			
			s[x][y] = '*';
			
			if(y*n+x+1 <= ans) in++;
		}
		
		//cout << a << ' ' << b << "\n";
		//for(int K = 0; K < n; K++){
			//cout << s[K] << "\n";
		//}
		//cout << ans << ' ' << in << "\n";
		cout << ans-in << "\n";
	}
	
	return 0;
}




















































