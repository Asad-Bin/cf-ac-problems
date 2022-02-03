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


const int MX = 2e3;
ll ara[MX+5][MX+5], x[2*MX+5], y[2*MX+5];
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    int n;
    
    cin >> n;
    
    for(int K = 1; K <= n; K++){
        for(int L = 1; L <= n; L++) sl(ara[K][L]);
    }
    
    for(int K = 1; K <= n; K++){
        for(int L = 0; L <= n; L++){
            x[K+L] += ara[K][L];
            y[K-L+n] += ara[K][L];
        }
    }
    // for(int K = 2; K <= n; K++){
        // for(int L = 0; L <= n; L++){
            // if(K+L > n || 1+L > n) break;
            // x[1][K] += ara[1+L][K+L];
        // }
    // }
    
    
    // for(int K = 1; K <= n; K++){
        // for(int L = 0; L <= n; L++){
            // if(L+K <= n+1){
                // y[1][L+K-1] += ara[K][L];
            // }
            // else{
                // y[L][n] += ara[K][L];
            // }
        // }
    // }
    // for(int K = 2; K <= n; K++){
        // for(int L = 0; L <= n; L++){
            // if(K+L > n || n-L < 1) break;
            // y[K][n] += ara[K+L][n-L];
        // }
    // }
    
    // for(int K = 1; K <= n; K++) cout << x[K][1] << ' ';
    // cout << "\n";
    // for(int K = 2; K <= n; K++) cout << x[1][K] << ' ';
    // cout << "\n";
    // for(int K = 1; K <= n; K++) cout << y[1][K] << ' ';
    // cout << "\n";
    // for(int K = 2; K <= n; K++) cout << y[K][n] << ' ';
    // cout << "\n";
    
    
    ll mx1, mx2, mid, x1, y1, x2, y2;
    mx1 = mx2 = 0;
    for(int K = 1; K <= n; K++){
        for(int L = 1; L <= n; L++){
            mid = x[K+L] + y[n+K-L];
            // if(K < L){
                // mid = x[1][L-K+1];
            // }
            // else{
                // mid = x[K-L+1][1];
            // }
            // debug(K, L, mid);
            
            // if(L+K <= n+1){
                // mid += y[1][L+K-1];
                // //debug(K, L, "check");
            // }
            // else{
                // mid += y[L][n];
            // }
            debug(K, L, mid);
            mid -= ara[K][L];
            
            if(!((K+L)&1) && mid >= mx1){
                mx1 = mid;
                x1 = K;
                y1 = L;
            }
            if(((K+L)&1) && mid >= mx2){
                mx2 = mid;
                x2 = K;
                y2 = L;
            }
            debug(K, L, ara[K][L], mid, mx1, mx2);
        }
    }
    
    cout << mx1+mx2 << "\n";
    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << "\n";
    
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































