//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 02 07 2020

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
    return (a*b/gcd(a, b));
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

int bfs(int source, int destination)
{
    queue<int> Q;
    vector<int> level(20005, -1);
    int u;
    Q.push(source);
    level[source] = 0;

    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        
        if(u==destination){
			return level[u];
		}
        
        if(u<destination && level[u*2]==-1){
			level[u*2] = level[u] + 1;
			Q.push(u*2);
		}
		if(u>1 && level[u-1]==-1){
			level[u-1] = level[u] + 1;
			Q.push(u-1);
		}
        
        /*for(int K=0; K<edge[u].size(); K++){
            v = edge[u][K];
            if(level[v]==-1){
                level[v] = level[u] + 1;
                Q.push(v);
                // can be matched with destination here to get the distance.
                // Or, can be calculated new persons or nodes comes in
                // consideration for the first time.
            }
        }*/
    }

    return 0;
}

void task()
{
    //code here...
    
    int n, m;
    
    cin >> n >> m;
    
	if(n>=m){
		cout << n-m << "\n";
		return;
	}
	
	int ans = bfs(n, m);
	
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

