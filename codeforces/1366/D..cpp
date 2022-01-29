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


vector<int> primes;
vector<bool> mark(10000*1000+5);
void sieve(int n)
{
    int limit = sqrt(n+1.0)+2;
    
    mark[1] = 1;
    
    for(int K = 4; K <= n; K+=2) mark[K] = 1;
    
    primes.PB(2);
    for(int K = 3; K <= n; K+=2){
        if(!mark[K]){
            primes.PB(K);
            
            if(K <= limit){
                for(int L = K*K; L <= n; L+=K*2){
                    mark[L] = 1;
                }
            }
        }
    }
}
const int MX = 5e5;
const int MXI = 1e7;
int ara[MX+5];
bitset<MXI+5> check;
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    int n;
    
    sieve(1e7+1);
    
    cin >> n;
    
    for(int K = 0; K < n; K++) cin >> ara[K];
    
    vector<pii> sol(n);
    vi v;
    
    check.reset();
    for(int K = 0; K < n; K++){
        int x = ara[K];
        
        v.clear();
        for(int L = 0; primes[L]*primes[L] <= x; L++){
            if(x%primes[L]==0){
                while(x%primes[L]==0) x /= primes[L];
                v.PB(primes[L]);
                check[primes[L]] = true;
            }
        }
        if(x != 1 && x < ara[K]){
            v.PB(x);
            check[x] = true;
        }
        
        int a = -1, b = -1;
        if(sz(v) >= 2){
            int num = 1;
            for(int L = 1; L < sz(v); L++){
                num *= v[L];
            }
            
            a = v[0];
            b = num;
                
                // for(int M = L+1; M < sz(v); M++){
                    // if(!check[v[L]+v[M]]){
                        // a = v[L];
                        // b = v[M];
                        // break;
                    // }
                // }
                // check[v[L]] = false;
                // if(a != -1){
                    // for(int M = L+1; M < sz(v); M++) check[v[M]] = false;
                    // break;
                // }
            // }
        }
        
        if(a != -1) sol[K] = {a, b};
        else sol[K] = {-1, -1};
    }
    
    for(auto x:sol) cout << x.fi << ' ';
    cout << "\n";
    for(auto x:sol) cout << x.se << ' ';
    cout << "\n";
    
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































