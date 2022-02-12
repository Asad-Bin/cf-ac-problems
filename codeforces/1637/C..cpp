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


const int MX = 1e5;
int ara[MX+5];
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    int t, n;
    
    cin >> t;
    while(t--){
		cin >> n;
		
		for(int K = 0; K < n; K++) cin >> ara[K];
		
		int cnt = 0;
		int odd = 0;
		int num = 0;
		for(int K = 1; K < n-1; K++){
			cnt += ara[K]/2;//
			num += (ara[K] > 1 ? 1 : 0);
			odd += (ara[K]&1);
		}
		
		if(num==0 || (num==1 && n==3 && odd==1)){
			cout << "-1\n";
			continue;
		}
		
		ll ans = 0;
		cnt = 0;
		for(int K = 1; K < n-1; K++){
			if(ara[K]%2==1) cnt++;
			
			//ans += (ara[K])/2;
		}
		
		//ans += cnt;
		//for(int K = 1; cnt && K < n-1; K++){
			//while(cnt && ara[K]>1){
				//ara[K] -= 2;
				//cnt--;
			//}
		//}
		
		//for(int K = 1; K < n-1; K++) cout << ara[K] << ' ';
		//cout << "\n";
		
		//if(cnt > 0){
			//cout << "-1\n";
			//continue;
		//}
		
		
		for(int K = 1; K < n-1; K++){
			//if(ara[K]%2==1) ara[K]++;
			
			ans += (ara[K]+1)/2;
		}
		
		//for(int K = 1; K < n-1; K++){
			//ans += (ara[K])/2;
		//}
		
		
		//ans += (cnt+1)/2;
		
		cout << ans << "\n";
	}
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}









