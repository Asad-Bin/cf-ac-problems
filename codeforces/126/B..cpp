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


const int MX = 1e6;
string s;
int pi[MX+5];
void prefixFunction()
{
    // char name[100] = {"asad"};
    // int n = strlen(name);
    // debug(n);
    // n = strlen(name+1);
    // debug(n);
    
    s = "."+s;
    int now;
    pi[1] = now = 0;
    int len = sz(s)-1;
    
    int ans = -1;
    for(int K = 2; K <= len; K++){
        while(now > 0 && s[now + 1] != s[K]) now = pi[now];
        
        if(s[now+1] == s[K]){
            now++;
            //pi[K] = now;
            //debug(K, s[K], now, pi[K], ans);
        }
        //else{
            //pi[K] = now = -1;
        //}
        pi[K] = now;
        
        debug(K, s[K], now, pi[K], ans);
    }
    
    debug(pi[len]);
    if(pi[len] > 0){
        for(int K =1; K < len; K++){
            if(pi[K] == pi[len]){
                for(int L = 1; L <= pi[K]; L++) cout << s[L];
                cout << "\n";
                return;
            }
        }
    }
    if(pi[pi[len]] > 0){
        for(int L = 1; L <= pi[pi[len]]; L++) cout << s[L];
        cout << "\n";
        return;
    }
    
    cout << "Just a legend" << "\n";
    
    // for(int K = pi[len-1]+1; K < len-pi[len-1]-1; K++) ans = max(ans, pi[K]);
    // return min(ans, pi[len-1])+1;
}
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    
    cin >> s;
    
    prefixFunction();
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































