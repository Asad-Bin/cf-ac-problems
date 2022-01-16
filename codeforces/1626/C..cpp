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


const int MX = 1e4;
ll k[MX+5], h[MX+5];
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    ll t, n;
    
    cin >> t;
    while(t--){
        cin >> n;
        
        for(int K = 0; K < n; K++) cin >> k[K];
        for(int K = 0; K < n; K++) cin >> h[K];
        
        ll ans = 0;
        
        // int time = 1000 * 1000 * 1000 + 5;
        // for(int K = n-1; K >= 0; K--){
            // int i = h[K];
            // if(k[K] > time)
            
            // while(i){
                // ans += i;
                // i--;
            // }
        // }
        
        vi v;
        ll x = 0;
        for(int K = 0; K < n; K++){
            ans += (h[K]*(h[K]+1)/2LL); //-(x*(x+1)/2LL);
            v.PB(K);
            //x = h[K];
            
            debug(K, k[K], h[K], ans);
            if(K < n-1 && h[K+1] > k[K+1]-k[K]){
                //x = h[K];
                    // ans -= (h[K]*(h[K]+1)/2LL);
                    // h[K+1] = max(h[K+1], h[K]+k[K+1]-k[K]);
                while(!v.empty() && h[K+1] > k[K+1]-k[v.back()]){
                    ans -= (h[v.back()]*(h[v.back()]+1)/2LL);
                    h[K+1] = max(h[K+1], h[v.back()]+k[K+1]-k[v.back()]);
                    
                    debug(k[K+1], k[v.back()], h[K+1], h[v.back()], ans);
                    v.pop_back();
                }
            }
            else x = 0;
            
            //debug(h[K], h[v.empty() ? K+1 : v.back()+1], x, (h[v.empty() ? K+1 : v.back()+1]*(h[v.empty() ? K+1 : v.back()+1]+1)/2LL), (x*(x+1)/2LL), ans);
        }
        
        cout << ans << "\n";
    }
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































