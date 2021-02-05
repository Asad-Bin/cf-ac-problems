//...Bismillahir Rahmanir Rahim...
 
#include <bits/stdc++.h>
using namespace std;
 
// typedefs...
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
 
// constants...
const double PI = acos(-1);
const int MOD = 1e9+7; // 998244353;
const int MXS = 2e5+5;
const int MXI = 1e9+5;
const ll MXL = 1e18+5;
 
// defines...
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
 
// chess moves...
// int dx[] = {+0, +0, -1, +1}; ///Up-down, Left-Right
// int dy[] = {+1, -1, +0, +0};
// int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's Move
// int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
// int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2}; ///Knight's Move
// int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};

// structs...
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const{ auto hash1 = hash<T1>{}(p.first); auto hash2 = hash<T2>{}(p.second); return hash1 ^ hash2;} 
};

// functions...
ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll comb(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}


void task()
{
	// Code here.. ..
	
	int t, n, m, a[100005], b[100005], c[100005], ara[100005];
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		vector<vector<vi> > color(n+5, vector<vi> (2));
		for(int K=0; K<n; K++) cin >> a[K];
		for(int K=0; K<n; K++){
			cin >> b[K];
			if(a[K]!=b[K]) color[b[K]][0].PB(K);
			else color[b[K]][1].PB(K);
		}
		for(int K=0; K<m; K++) cin >> c[K];
		
		bool ok = 1;
		int x = -1;
		for(int K=m-1; ok && K>=0; K--){
			if(sz(color[c[K]][0])==0){
				if(sz(color[c[K]][1])==0){
					if(x!=-1) ara[K] = x;
					else ok = 0;
				}
				else{
					ara[K] = color[c[K]][1].back()+1;
					if(x==-1) x = ara[K];
				}
			}
			else{
				ara[K] = color[c[K]][0].back()+1;
				if(x==-1) x = ara[K];
				color[c[K]][0].pop_back();
			}
		}
		
		for(int K=1; K<=n; K++){
			if(sz(color[K][0])>0){
				ok = 0;
				break;
			}
		}
		if(!ok){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for(int K=0; K<m; K++) cout << ara[K] << ' ';
		cout << "\n";
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	task();
    return 0;
}
