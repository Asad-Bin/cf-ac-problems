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


const ll MX = 1e3;
const ll MXI = 1e9+7;
ll b[MX+5], c[MX+5], s[MX+5], dp[MX+5][12009];
ll calc(ll at, ll u)
{
    if(u < 0) return -MXI;
    if(at == -1){
        return 0;
    }
    
    if(dp[at][u] != -1) return dp[at][u];
    
    ll ans = max(calc(at-1, u), calc(at-1, u-s[at])+c[at]);
    
    return dp[at][u] = ans;
}
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    ll t, n, k;
    
    for(int K = 2; K <= 1000; K++) b[K] = 1e9+7;
    b[1] = 0;
    for(int K = 1; K <= MX; K++){
        for(int L = 1; L <= K; L++){
            if(K+K/L <= 1000) b[K+K/L] = min(b[K+K/L], b[K] + 1);
        }
    }
    
    cin >> t;
    while(t--){
        cin >> n >> k;
        
        for(ll K = 0; K < n; K++) cin >> s[K];
        for(ll K = 0; K < n; K++) cin >> c[K];
        
        for(ll K = 0; K < n; K++){
            // if(b[K] == 1){
                // s[K] = 0;
                // continue;
            // }
            
            // ll cnt = 0, mid;
            // ll i = 1;
            // while(i < b[K]){
                // //debug(K, b[K], i, cnt);
                // if(i+i > b[K]){
                    // b[K] -= i;
                    // while(i >= 1){
                        // mid = (b[K])/i;
                        // //debug(b[K], i, mid);
                        // cnt += mid;
                        // b[K] -= i*mid; 
                        // i /= 2;
                    // }
                    
                    // //debug(K, b[K], i, cnt);
                    // break;
                // }
                // i = i+i;
                // cnt++;
            // }
            
            
            
            s[K] = b[s[K]];
            //debug(K, b[K], i, s[K]);
        }
        
        ll sum = 0;
        for(ll K = 0; K < n; K++){
            sum += s[K];
        }
        // cout << "\n";
        // for(ll K = 0; K < n; K++) cout << c[K] << ' ';
        // cout << "\n";
        
        memset(dp, -1LL, sizeof dp);
        cout << calc(n-1, min(k, sum)) << "\n";
    }
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































