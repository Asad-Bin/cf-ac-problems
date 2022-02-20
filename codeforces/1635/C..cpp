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
ll ara[MX+5];

int main()
{
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		if(ara[n-1] < ara[n-2]){
			cout << "-1\n";
		}
		else{
			if(ara[n-1] >= 0){
				cout << n-2 << "\n";
				for(int K = 0; K < n-2; K++) cout << K+1 << ' ' << n-1 << ' ' << n << "\n";
			}
			else{
				bool ok = 1, p = 0;
				for(int K = n-3; K >= 0; K--){
					if(ara[K] > ara[K+1]){
						ok = 0;
						break;
					}
					if(ara[K]-ara[n-1] <= ara[K]){
						cout << K << "\n";
						for(int L = K-1; L >= 0; L--) cout << L+1 << ' ' << n-1 << ' ' << n << "\n";
						p = 1;
						
						break;
					}
				}
				
				if(!ok){
					cout << "-1\n";
				}
				else if(!p){
					cout << "0\n";
				}
			}
		}
	}
	
	return 0;
}




















































