#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<long long>
#define PB push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int MX = 1e3;
int ara[MX+5][6], day[6];

int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
	
	int t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		memset(ara, 0, sizeof ara);
		memset(day, 0, sizeof day);
		
		for(int K=0; K<n; K++){
			for(int L=0; L<5; L++){
				cin >> ara[K][L];
				if(ara[K][L]) day[L]++;
			}
		}
		
		bool ok = 0;
		for(int K=0; K<4 && !ok; K++){
			if(day[K]*2>=n){
				for(int L=K+1; L<5; L++){
					bool f = 1;
					int cnt = 0, x = 0;
					for(int M=0; M<n; M++){
						if(ara[M][K] == 0 && ara[M][L] == 1) x++;
						else if(ara[M][K] == 1 && ara[M][L] == 1) cnt++;
						else if(ara[M][K] == 1) {}
						else f = 0;
					}
					
					if(f && cnt>=n/2-x){
						ok = 1;
						debug(K, L);
						break;
					}
				}
			}
		}
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}














































