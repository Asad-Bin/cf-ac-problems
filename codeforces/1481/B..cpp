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
	
	int t, n, k;
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		
		int ara[n];
		for(int K=0; K<n; K++){
			cin >> ara[K];
		}
		
		if(n==1){
			cout << "-1" << "\n";
			continue;
		}
		
		ll ans = 0, cnt, in, pre = -1;
		bool ok = 0;
		while(k>0){
			in = 0LL;
			cnt = 1;
			pre = -1;
			
			for(int K=0; K<n-1; K++){
				if(ara[K]==ara[K+1]){
					cnt++;
				}
				else if(ara[K]<ara[K+1]){
					in = (ll)(min(pre!=-1?ara[pre]:MXI, ara[K+1])-ara[K])*cnt;
					
					if(in>k){
						//K -= (k-ara[K+1]+ara[K]+1)/(ara[K+1]-ara[K]);
						//ans += K+1;
						//k = 0;
						k %= cnt;
						if(k==0) ans = K-cnt+1+1;
						else ans = K-k+1+1;
						k -= in;
						
						ok = 1;
						break;
					}
					else if(in==k){
						ans = K-cnt+1+1;
						k -= in;
						
						ok = 1;
						break;
					}
					
					for(int L=K; L>K-cnt; L--){
						ara[L] = min(pre!=-1?ara[pre]:MXI, ara[K+1]);
					}
					k -= in;
					
					break;
				}
				
				if(K==n-2){
					ans = -1;
					
					ok = 1;
					break;
				}
				
				
				if(ara[K]>ara[K+1]){
					cnt = 1;
					pre = K;
				}
			}
			
			//for(auto x:ara) cout << x << ' ';
			//cout << k << ' ' << ans << "\n";
			if(ok) break;
		}
		
		cout << ans << "\n";
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
