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
int ara[MX+5], st[MX+5], en[MX+5];
bool mark[MX+5];
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    int n;
    
    memset(st, -1, sizeof st);
    memset(en, -1, sizeof en);
    
    vector<pii> v;
    
    cin >> n;
    for(int K = 0; K < n; K++){
        cin >> ara[K];
        
        st[ara[K]] = min((st[ara[K]]==-1?MX+5:st[ara[K]]), K);
        en[ara[K]] = max(en[ara[K]], K);
    }
    
    int shesh = -1, line = -1;
    bool on = 0;
    for(int K = 0; K < n; K++){
        mark[K] = on;
        
        debug(K, ara[K], en[ara[K]], line, shesh, on);
        
        if(en[ara[K]] != K && en[ara[K]] > shesh){
            if(shesh == -1) shesh = line = en[ara[K]];
            else shesh = en[ara[K]];
            on = 1;
            
            continue;
        }
        
        if(K == line){
            mark[K] = 0;
            
            line = shesh;
        }
        if(K == shesh){
            mark[K] = 0;
            shesh = line = -1;
        }
        
        if(shesh == -1) on= 0;
        
        debug(K, ara[K], en[ara[K]], line, shesh, mark[K]);
    }
    
    int ans = 0;
    for(int K = 0; K < n; K++) if(mark[K]) ans++;
    
    cout << ans << "\n";
    
    // for(int K = 1; K<= n; K++){
        // if(st[K] != -1 && en[K] != -1 && st[K] != en[K] && st[K]+1 != en[K]){
            // v.PB({st[K], en[K]});
        // }
    // }
    
    
    // sort(v.begin(), v.end());
    
    // debug(v);
    // int i = v[0].fi, j = v[0].se;
    
    // int cnt = 0, ans = 0;
    // for(int K = 1; K < sz(v); K++){
        // if(v[K].fi > j){
            // ans += j-i-1-(cnt ? 1 :0);
            
            // for(int L = 0; cnt && L < K; L++){
                // if(i < v[L].fi && v[L].se < j){
                    // ans--;
                    // break;
                // }
            // }
            
            // i = v[K].fi;
            // j = v[K].se;
            // cnt = 0;
            
            // continue;
        // }
        
        // if(i < v[K].fi && j < v[K].se) cnt++;
        // else if(v[K].fi < i && v[K].se < j) cnt++;
        // i = min(i, v[K].fi);
        // j = max(j, v[K].se);
        
        // debug(v[K], i, j, cnt, ans);
    // }
    // ans += (j-i-1-(cnt ? 1 : 0));
    // for(int L = 0; cnt && L < sz(v); L++){
        // if(i < v[L].fi && v[L].se < j){
            // ans--;
            // break;
        // }
    // }
    
    //cout << ans << "\n";
    
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































