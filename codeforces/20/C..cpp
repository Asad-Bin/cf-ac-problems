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


struct Node{
    int at;
    ll cost;
    
    Node(int _at, ll _cost){
        at = _at;
        cost = _cost;
    }
};
bool operator<(Node A, Node B){
    return A.cost > B.cost;
}
struct Edge{
    int v, w;
    
    Edge(int _v, int _w){
        v = _v;
        w = _w;
    }
};
const int MX = 1e5;
vector<Edge> adj[MX+5];
priority_queue<Node> PQ;
ll dist[MX+5];
int path[MX+5];
int n;
void dijkstra(int source, int dest)
{
    memset(dist, -1LL, sizeof dist);
    memset(path, -1, sizeof path);
    
    dist[source] = 0;
    while(!PQ.empty()) PQ.pop();
    PQ.push(Node(source, 0));
    
    while(!PQ.empty()){
        Node u = PQ.top();
        PQ.pop();
        
        if(u.cost != dist[u.at]) continue;
        
        for(Edge e:adj[u.at]){
            if(dist[e.v]==-1 || dist[e.v]>(ll)u.cost+e.w){
                dist[e.v] = (ll)u.cost+e.w;
                PQ.push(Node(e.v, dist[e.v]));
                path[e.v] = u.at;
            }
        }
    }
    
    if(dist[dest] == -1){
        cout << "-1" << "\n";
        return;
    }
    
    debug(dist[n]);
    
    int i = n;
    vi v;
    v.PB(n);
    while(i != 1 && i != -1){
        i = path[i];
        v.PB(i);
        debug(i);
    }
    
    reverse(v.begin(), v.end());
    
    for(auto x:v) cout << x << ' ';
    cout << "\n";
}
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    int m, u, v, w;
    
    cin >> n >> m;
    
    while(m--){
        cin >> u >> v >> w;
        
        adj[u].PB(Edge(v, w));
        adj[v].PB(Edge(u, w));
    }
    
    dijkstra(1, n);
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}














































