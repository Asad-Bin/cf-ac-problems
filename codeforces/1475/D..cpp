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
ll a[MX+5], b[MX+5], v1[MX+5], v2[MX+5];
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    int t, n, m;
    
    cin >> t;
    while(t--){
        cin >> n >> m;
        
        for(int K = 0; K < n; K++) cin >> a[K];
        for(int K = 0; K < n; K++) cin >> b[K];
        
        int i = 0, j = 0;
        for(int K = 0; K < n; K++){
            if(b[K] == 1){
                v1[i++] = a[K];
            }
            else{
                v2[j++] = a[K];
            }
        }
        
        sort(v1, v1+i);
        reverse(v1, v1+i);
        sort(v2, v2+j);
        reverse(v2, v2+j);
        
        for(int K = 1; K < i; K++) v1[K] += v1[K-1];
        for(int K = 1; K < j; K++) v2[K] += v2[K-1];
        
        int cnt = 0, ans = 2*MX+5;
        int l = j;
        
        for(int K = -1; K <= i; K++){
            ll sum = 0;
            cnt = 0;
            
            if(K < i && K >= 0){
                sum += v1[K];
                cnt = K+1;
            }
            
            if(sum >= m){
                ans = min(ans, K+1);
                break;
            }
            
            while(l){
                if(v2[l-1] >= m-sum) l--;
                else break;
            }
            
            // int l = 0, r = j-1, mid;
            // while(l < r){
                // mid = (l+r)/2;
                
                // if(v2[mid] < m-sum){
                    // l = mid+1;
                // }
                // else{
                    // r = mid;
                // }
            // }
            
            if(l < j && v2[l] >= m-sum) cnt += 2*(l+1);
            else cnt = 2*MX+5;
            
            ans = min(ans, cnt);
            
            debug(K, v1[K], m-sum, l+1, v2[l], cnt, ans);
        }
        
        cout << (ans == 2*MX+5 ? -1 : ans) << "\n";
    }
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































