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
	
    int t, x1, p1, x2, p2;
    vi v1, v2;
    
    
    si(t);
    while(t--){
        sii(x1, p1);
        sii(x2, p2);
        
        v1.clear();
        v2.clear();
        
        while(true){
            if(x1) v1.PB(x1%10);
            if(x2) v2.PB(x2%10);
            
            x1 /= 10;
            x2 /= 10;
            
            if(!x1 && !x2) break;
        }
        
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        
        debug(v1, v2);
        
        if(sz(v1)+p1 == sz(v2)+p2){
            bool ok = 0;
            
            int mn = min(sz(v1), sz(v2));
            for(int K = 0; K < mn; K++){
                if(v1[K] > v2[K]){
                    printf(">\n");
                    ok = 1;
                    break;
                }
                else if(v1[K] < v2[K]){
                    printf("<\n");
                    ok = 1;
                    break;
                }
            }
            
            debug(mn, ok);
            if(!ok){
                if(sz(v1) == sz(v2)){
                    printf("=\n");
                }
                else if(sz(v1) > mn){
                    for(int K = mn; K < sz(v1); K++){
                        if(v1[K] > 0){
                            printf(">\n");
                            ok = 1;
                            break;
                        }
                    }
                    if(!ok) printf("=\n");
                }
                else{
                    for(int K = mn; K < sz(v2); K++){
                        if(v2[K] > 0){
                            printf("<\n");
                            ok = 1;
                            break;
                        }
                    }
                    if(!ok) printf("=\n");
                }
            }
        }
        else if(sz(v1)+p1 > sz(v2)+p2){
            printf(">\n");
        }
        else{
            printf("<\n");
        }
    }
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































