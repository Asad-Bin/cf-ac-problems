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


int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    int t;
    string s;
    
    si(t);
    while(t--){
        cin >> s;
        
        int n = (int)s.length();
        int pre = 0;
        for(int K = 0; K < n; K++){
            if(s[K] != s[0]) break;
            pre++;
        }
        
        int post = 0;
        for(int K = n-1; K >= 0; K--){
            if(s[K] != s[n-1]) break;
            post++;
        }
        
        bool ok = 0;
        if((pre != 0 && post != 0) && pre + post == n){
            s[0] = s.back();
            //cout << s << "\n";
            ok = 1;
            //continue;
        }
        
        if(!ok && pre != n && s[0] != s.back()){
            //debug(pre, post);
            // if(pre <= post){
                // while(pre--) s[pre] = s[n-1];
            // }
            // else{
                // while(post--) s[n-1-post] = s[0];
            // }
            
            s[0] = s.back();
        }
        cout << s << "\n";
        
        continue;
        int ab = 0, ba = 0;
        for(int K = 1; K < n; K++){
            if(s[K]=='a' && s[K-1] == 'b') ab++;
            else if(s[K] == 'b' && s[K-1] == 'a') ba++;
        }
        if(ab == ba) puts("ok");
        else puts("wa");
    }
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































