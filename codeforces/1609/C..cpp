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
int ara[MX+5], pre[MX+5], post[MX+5], res[MX+5], ok[MX+5], tot[MX+5];
vector<int> primes;
vector<bool> mark(1000007);
void sieve(int n)
{
    int i, j, limit = sqrt(n*1.) + 2;

    //mark[1] = 1;

    for(i = 4; i<=n; i+=2) mark[i] = 1;

    primes.push_back(2);

    for(i = 3; i <= n; i += 2)
    {
        if(!mark[i])
        {
            primes.push_back(i);

            if(i<=limit)
            {
                for(j = i*i; j <= n; j += i*2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}
ll fact(int n, int m)
{
    ll ans = 0;
    
    while(n--){
        ans += (m+1);
    }
    
    return ans+m;
}
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    int t, n, e;
    sieve(1000001);
    
    si(t);
    while(t--){
        sii(n, e);
        
        for(int K = 0; K < n; K++) si(ara[K]);
        
        memset(res, 0, sizeof res);
        memset(ok, 0, sizeof ok);
        memset(tot, 0, sizeof tot);
        
        
        
        memset(pre, 0, sizeof pre);
        memset(post, 0, sizeof post);
        
        int cnt = 0;
        for(int K = 0; K < n; K++){
            if(ok[K]) continue;
            cnt = 0;
            for(int L = K; L < n; L += e){
                if(!mark[ara[L]] && ara[L] != 1) pre[L] = cnt;
                
                if(ara[L] == 1) cnt++;
                else cnt = 0;
                
                ok[L] = 1;
            }
        }
        cnt = 0;
        memset(ok, 0, sizeof ok);
        for(int K = n-1; K >= 0; K--){
            if(ok[K]) continue;
            cnt = 0;
            for(int L = K; L >= 0; L -= e){
                if(!mark[ara[L]] && ara[L] != 1) post[L] = cnt;
                
                if(ara[L] == 1) cnt++;
                else cnt = 0;
                
                ok[L] = 1;
            }
        }
        
        ll ans = 0;
        for(int K = 0; K < n; K++){
            //debug(K, ara[K], pre[K], post[K]);
            ans += fact(pre[K], post[K]);
        }
        
        
        
        // for(int K = 0; K+e < n; K++){
            // if(mark[ara[K]] || mark[ara[K+e]] || (ara[K] != 1 && ara[K] == ara[K+e])) continue;
            // if(res[K] == 0) res[K] = 1;
            
            // if(ara[K+e] != 1) ok[K+e] = 1;
            // else{
                // res[K+e] = 1;
                // ok[K] = 1;
                
                // continue;
            // }
            
            // ara[K+e] *= ara[K];
            // res[K+e] = res[K]+1;
            // res[K] = 0;
            // debug(K, e, res[K], res[K+e], ok[K]);
            // ok[K] = 0;
        // }
        
        // // for(int K = 0; K+e < n; K++){
            // // if(res[K] && ok[K+1]){
                // // res[K+e] = 
            // // }
            
            // // ara[K+e] *= ara[K];
            // // res[K+e] = res[K]+1;
            // // res[K] = 0;
            // // debug(K, e, res[K], res[K+e], ok[K]);
            // // ok[K] = 0;
        // // }
        
        // for(int K = n-1; K-e >= 0; K--){
            // if(res[K]){
                // tot[K - e]  = fact(res[K-e]-1+res[K], res[K-e]);
                // //res[K - e] += res[K];
                // if(ok[K])tot[K - e] += fact(res[K]-1, res[K]-1);
            // }
        // }
        
        // ll ans = 0;
        // for(int K = 0; K < n; K++){
            // debug(K, res[K], ok[K]);
            // ans += (ok[K] ? tot[K] : 0);
        // }
        
        printf("%lld\n", ans);
    }
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































