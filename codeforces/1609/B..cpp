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
	
    int n, q, pos;
    char c;
    string s;
    set<int> ss;
    
    sii(n, q);
    
    cin >> s;
    
    for(int K = 2; K < n; K++){
        if(s[K] == 'c' && s[K-1] == 'b' && s[K-2] == 'a') ss.insert(K-2);
    }
    
    debug(ss);
    
    while(q--){
        si(pos);
        getchar();
        scanf("%c", &c);
        pos--;
        
        debug(pos, c, ss);
        
        s[pos] = c;
        
        if(c == 'a'){
            auto it = ss.find(pos-1);
            if(it != ss.end()){
                ss.erase(it);
                //printf("%d\n", sz(ss));
                
                    debug(pos, c, ss);
                //continue;
            }
            
            it = ss.find(pos-2);
            if(it != ss.end()){
                ss.erase(it);
                
                //printf("%d\n", sz(ss));
                
                    debug(pos, c, ss);
                //continue;
            }
        }
        else if(c == 'b'){
            auto it = ss.find(pos);
            if(it != ss.end()){
                ss.erase(it);
                // printf("%d\n", sz(ss));
                
                    debug(pos, c, ss);
                //continue;
            }
            
            it = ss.find(pos-2);
            if(it != ss.end()){
                ss.erase(it);
        
                // printf("%d\n", sz(ss));
                
                    debug(pos, c, ss);
                //continue;
            }
        }
        else{
            auto it = ss.find(pos);
            if(it != ss.end()){
                ss.erase(it);
                // printf("%d\n", sz(ss));
                
                    debug(pos, c, ss);
                //continue;
            }
            
            it = ss.find(pos-1);
            if(it != ss.end()){
                ss.erase(it);
                
                // printf("%d\n", sz(ss));
                //continue;
            }
        }
        
        if(c == 'a'){
            if(pos+2 < n && s[pos] == 'a' && s[pos+1] == 'b' && s[pos+2] == 'c') ss.insert(pos);
            // else{
                // ss.erase(pos-1);
                // ss.erase(pos-2);
            // }
        }
        else if(c == 'b'){
            if(pos > 0 && pos+1 < n && s[pos-1] == 'a' && s[pos] == 'b' && s[pos+1] == 'c') ss.insert(pos-1);
            // else{
                // ss.erase(pos);
                // ss.erase(pos-2);
            // }
        }
        else{
            if(pos > 1 && s[pos-2] == 'a' && s[pos-1] == 'b' && s[pos] == 'c') ss.insert(pos-2);
            // else{
                // ss.erase(pos);
                // ss.erase(pos-1);
            // }
        }
        
        printf("%d\n", sz(ss));
    }
    
    
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































