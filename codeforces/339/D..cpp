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
int num[MX+5], tree[4*MX+5];
void build(int at, int l, int r, bool f)
{
    if(l == r){
        tree[at] = num[l];
        return;
    }
    
    int mid = (l+r)/2;
    
    build(at*2, l, mid, f^1);
    build(at*2+1, mid+1, r, f^1);
    
    if(!f) tree[at] = tree[at*2] | tree[at*2+1];
    else tree[at] = tree[at*2] ^ tree[at*2+1];
}
void update(int at, int l, int r, int idx, int num, bool f)
{
    if(l == r){
        tree[at] = num;
        return;
    }
    
    int mid = (l+r)/2;
    
    if(idx <= mid) update(at*2, l, mid, idx, num, f^1);
    else update(at*2+1, mid+1, r, idx, num, f^1);
    
    if(!f) tree[at] = tree[at*2] | tree[at*2+1];
    else tree[at] = tree[at*2] ^ tree[at*2+1];
}
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    int n, m, p, b;
    
    cin >> n >> m;
    
    int s = 1;
    for(int K = 1; K <= n; K++) s *= 2;
	
    for(int K = 1; K <= s; K++) cin >> num[K];
    
    // 1 for or
    // 0 for xor
    build(1, 1, s, (n%2==1 ? 0 : 1));
    
    while(m--){
        cin >> p >> b;
        
        update(1, 1, s, p, b, (n%2==1 ? 0 : 1));
        cout << tree[1] << "\n";
    }
    
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































