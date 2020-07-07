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


vector<vi> edge(101);
vector<pair<pii, int> > mp;
vi color(101, 1);

bool dfs(int source, int destination, int pre)
{
	int u = source, v;
	
	if(u==destination) return 1;
	
	color[u] = 0;                    // 0 - grey...
	
	for(int K=0; K<(int)edge[u].size(); K++){
		v = edge[u][K];
		
		for(auto it:mp){
			if((it.first.first==u && it.first.SE==v) || (it.first.first==v && it.first.SE==u)){
				if(pre==it.SE && color[v]==1){             // 1 - white...
					//cout << "u = " << u << " v = " << v << ' ' << pre << "\n";
					if(dfs(v, destination, pre)==1) return 1;
				}
			}
		}
		//auto it = find(mp.begin(), mp.end(), MP(u, v));
		//ss.insert(it->SE);
	}
	
	color[u] = -1;				 // -1 - black...
	
	return 0;
}
void task()
{
    //code here...
    
    int n, m, a, b, c, q;
    
    cin >> n >> m;
    while(m--){
		cin >> a >> b >> c;
		
		mp.PB(MP(MP(a,b), c));
		mp.PB(MP(MP(b,a), c));
		
		edge[a].PB(b);
		edge[b].PB(a);
	}
	
	cin >> q;
	while(q--){
		cin >> a >> b;
		
		int ans = 0;
		//ss.clear();
		for(int K=0; K<100; K++){
			fill(color.begin(), color.end(), 1);
			if(dfs(a, b, K+1)==1) ans++;
		}
		
		cout << ans << "\n";
	}
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

