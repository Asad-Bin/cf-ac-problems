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

void print(ll x){
    printf("%lld\n", x);
}
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    ll t, x, n;
    
    sl(t);
    while(t--){
        sll(x, n);
        
        if(n == 0){
            printf("%lld\n", x);
            continue;
        }
        
        n--;
        if(x&1) x++;
        else x--;
        
        if(x&1) x -= (n/4)*4 + (n%4==3 ? n+1-n-n+1 : (n%4==2 ? -n-n-1 : (n%4==1 ? -n-1 : 0)));
        else x += (n/4)*4 + (n%4==3 ? n+1-n-n+1 : (n%4==2 ? -n-1-n : (n%4==1 ? -n-1 : 0)));
        
        debug((n/4)*4);
        printf("%lld\n", x);
        
        /*
        ll mid = n/4;
        if(n%4>=2) mid++;
        
        ll ans = mid*(5 + (mid-1)*8)/2;
        mid = n/4;
        ans -= mid*(9 + (mid-1)*8)/2;
        
        if(n%4==1) ans += (n+1);
        if(n%4==3) ans -= (n+1);
        
        debug(x, n, ans);
        
        
        mid = ans;
        if(n%4==1 || n%4==2){
            //mid -= n;
            
            if(abs(x)&1) printf("%lld\n", x+abs(mid));
            else printf("%lld\n", x-abs(mid));
        }
        else{
            if(abs(x)&1) printf("%lld\n", x-abs(mid));
            else printf("%lld\n", x+abs(mid));
        }*/
    }
    
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































