//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber

#include <bits/stdc++.h>

using namespace std;

// typedefs...
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

// constants...
const double PI = acos(-1);

// defines...
#define MP make_pair
#define PB push_back
#define FI first
#define SE second
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return ((ll)a*b/(ll)gcd(a, b));
}
ll comb(ll a, ll b)
{
    ll x = max(a-b, b), ans=1;

    for(ll K=a, L=1; K>=x+1; K--, L++){
        ans *= K;
        ans /= L;
    }

    return ans;
}


vector<vector<int> > edge(51);
int n, m;
vector<bool> mark(51, 0);

ll bfs(int source)
{
	ll ans = 1;
    queue<int> Q;
    //vi level(n+1, -1);
    
    int u, v;
    Q.push(source);
    //level[source] = 0;
    mark[source] = 1;

    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        //mark[u] = 1;
        if(u!=source) ans *= 2;

        for(int K=0; K<(int)edge[u].size(); K++){
            v = edge[u][K];
            if(!mark[v]){
                //level[v] = level[u] + 1;
                Q.push(v);
                mark[v] = 1;
            }
        }
    }

    return ans;
}
void task()
{
    //code here...
    
    int a, b;
    cin >> n >> m;
    
    while(m--){
		cin >> a >> b;
		edge[a].PB(b);
		edge[b].PB(a);
	}
	
	ll ans = 1;
	for(int K=1; K<=n; K++){
		if(!mark[K]){
			ans *= bfs(K);
		}
	}
	
	cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

