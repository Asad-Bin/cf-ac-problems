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
string s[MX+5];
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
        
        for(int K = 0; K < n; K++) cin >> s[K];
        
        bool ok = 0;
        for(int K = 0; K < n; K++){
            if(sz(s[K]) == 1) ok = 1;
        }
        
        if(ok) {
            cout << "YES\n";
            continue;
        }
        
        for(int K = 0; K < n; K++){
            if((sz(s[K])==2 && s[K][0]==s[K][1]) || (sz(s[K])==3 && s[K][0]==s[K][2])) ok = 1;
        }
        
        if(ok) {
            cout << "YES\n";
            continue;
        }
        
        map<string, int > mp;
        string t;
        for(int K = 0; K < n; K++){
            mp[s[K]]++;
            
            t = s[K];
            reverse(t.begin(), t.end());
            if(mp[t]) ok = 1;
        }
        
        if(ok) {
            cout << "YES\n";
            continue;
        }
        
        mp.clear();
        for(int K = 0; K < n; K++){
            mp[s[K]]++;
            
            // t = "";
            // t += s[K][1];
            // t += s[K][0];
            // if(sz(s[K])==3 && mp[t]) ok = 1;
            
            t = "";
            t += s[K][2];
            t += s[K][1];
            if(sz(s[K])==3 && mp[t]) ok = 1;
            debug(t);
        }
        
        if(ok) {
            cout << "YES\n";
            continue;
        }
        
        mp.clear();
        for(int K = n-1; K >= 0; K--){
            mp[s[K]]++;
            
            t = "";
            t += s[K][1];
            t += s[K][0];
            if(sz(s[K])==3 && mp[t]) ok = 1;
            
            // t = "";
            // t += s[K][2];
            // t += s[K][1];
            // if(sz(s[K])==3 && mp[t]) ok = 1;
            // debug(t);
        }
        
        if(ok) {
            cout << "YES\n";
            continue;
        }
        
        cout << "NO\n";
    }
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































