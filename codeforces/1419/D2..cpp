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
const int Mod = 1e9+7; // 998244353;
const int MXS = 2e5+5;
const int MXI = 1e9+5;
const ll MXL = 1e15+5;
const int INF = 1e5+5;

// defines...
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
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
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

// functions...
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return (a/gcd(a, b)*b);
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


void task()
{
    //code here...
    
    int n;
    
    cin >> n;
    
    vi ara(n), ans;
    for(int K=0; K<n; K++) cin >> ara[K];
    
    sort(all(ara));
    
    int i = 0, j = n-1;
    bool f = 1;
    while(i<=j){
		if(f){
			ans.PB(ara[j]);
			j--;
		}
		else{
			ans.PB(ara[i]);
			i++;
		}
		
		f ^= 1;
	}
	
	int sss;
	
	if(n%2==0) sss = ans[n-3];
	else sss = ans[n-2];
	
	if(n%2==1){
		for(int K=n-2; K>=0; K-=2){
			for(int L=1; L<K; L+=2){
				if(ans[K]==sss && ans[L-1]>ans[K] && ans[L+1]>ans[K]){
					swap(ans[K], ans[L]);
				}
			}
		}
	}
	else{
		for(int K=n-3; K>=0; K-=2){
			for(int L=1; L<K; L+=2){
				if(ans[K]==sss && ans[L-1]>ans[K] && ans[L+1]>ans[K]){
					swap(ans[K], ans[L]);
				}
			}
		}
	}
	
	int tot = 0;
	
	for(int K=1; K<n-1; K++){
		if(ans[K]<ans[K-1] && ans[K]<ans[K+1]) tot++;
	}
	
	cout << tot << "\n";
	for(auto it:ans) cout << it << ' ';
	cout << "\n";
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


