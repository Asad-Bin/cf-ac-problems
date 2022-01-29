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


const int MX = 2e6;
int b[MX+5];
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    int t, n;
    string s;
    
    cin >> t;
    while(t--){
        cin >> s;
        n = (int)s.length();
        
        //  abcdcba
        int i = -1, j = n;
        while(i < j && s[i+1] == s[j-1]){
            i++;
            j--;
        }
        
        debug(i, j);
        
        
        string T = s.substr(i+1, max(0, j-i-1));
        //debug(T);
        string P = T;
        reverse(P.begin(), P.end());
        P = T+"#"+P;
        
        int at = 0, now = -1, m = sz(P);
        b[0] = -1;
        while(at < m){
            while(now >= 0 && P[at] != P[now]) now = b[now];
            at++;
            now++;
            b[at] = now;
        }
        
        // for(int K = 0; K < m; K++) cout << b[K] << ' ' ;
        // cout << "\n";
        int a = now;
        //debug(a);
        
        
        P = T;
        reverse(P.begin(), P.end());
        P = P+"#"+T;
        
        at = 0, now = -1, m = sz(P);
        b[0] = -1;
        while(at < m){
            while(now >= 0 && P[at] != P[now]) now = b[now];
            at++;
            now++;
            b[at] = now;
        }
        
        // for(int K = 0; K < m; K++) cout << b[K] << ' ' ;
        // cout << "\n";
        int b = now;
        //debug(b);
        
        
        P = s.substr(0, i+1);
        T = s.substr(max(i+1, j), max(0, n-max(i+1, j)));
        // debug(P, T);
        string sol = P + (a>=b ? s.substr(i+1, a) : s.substr(max(0, j-b), b)) + T;
        
        cout << sol << "\n";
        debug("----------------------------------");
        
        //if(i < j) i++;
        
        // // int a = 0, b = 0;
        // // for(int K = j-1; K > i; K--){
            // // if(s[K] == s[i+1]){
                // // int q = K, p = i+1;
                
                // // while(p < q && s[p]==s[q]){
                    // // p++;
                    // // q--;
                // // }
                // // if(p == q || q+1==p){
                    // // a = K-i;
                    // // break;
                // // }
            // // }
        // // }
        
        // // for(int K = i+1; K < j; K++){
            // // if(s[K] == s[j-1]){
                // // int p = K, q = j-1;
                
                // // while(p < q && s[p]==s[q]){
                    // // p++;
                    // // q--;
                // // }
                // // if(p == q || q+1== p){
                    // // b = j-K;
                    // // break;
                // // }
            // // }
        // // }
        
        // string str = s.substr(0, i+1+(a>=b ? a : 0))+s.substr(max(i+1, j-(a<b ? b : 0)), n-j+(a>b ? 0 : b));
        // debug(i, j, a, b, str, max(i+1, j), n-j+(a>b ? 0 : b));
        // cout << str << "\n";
     }
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































