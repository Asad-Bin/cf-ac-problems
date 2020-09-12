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
const int MOD = 1e9+7; // 998244353;
const int MXS = 2e5+5;
const int MXI = 1e9+5;
const ll MXL = 1e15+5;
const int INF = 1e9+5;

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
ll gcd(ll a, ll b) {
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


bool func(int a, int b){
	return abs(a)>abs(b);
}
void task()
{
	// Code here...
	
	ll t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		vl ara(n);
		for(ll K=0; K<n; K++) cin >> ara[K];
		sort(ara.begin(), ara.end());
		
		ll ans = ara[n-1];
		ll i = 0, j = n-2, cnt = 0;
		while(i<n-1 && j>0 && cnt<=2){
			if(ara[i]*ara[i+1]>=ara[j]*ara[j-1]){
				ans *= ara[i]*ara[i+1];
				i += 2;
			}
			else{
				ans *= ara[j] * ara[j-1];
				j -= 2;
			}
			cnt += 2;
		}
		
		//if(ans*ara[i]>=ans*ara[j]) ans *= ara[i];
		//else ans *= ara[j];
		
		if(ans<0){
			sort(ara.begin(), ara.end(), func);
			
			/*for(int K=i; K<=j; K++){
				if(ara[K]<=0){
					ans *= ara[K];
					
					break;
				}
				if(K==n-1){
					if(ara[3]<0){
						ans /= ara[3];
						ans *= ara[4] * ara[5];
					}
					else if(ara[2]<0){
						ans /= ara[2];
						ans *= ara[4] * ara[5];
					}
					else if(ara[1]<0){
						ans /= ara[1];
						ans *= ara[4] * ara[5];
					}
					else if(ara[0]<0){
						ans /= ara[0];
						ans *= ara[4] * ara[5];
					}
					else{
						ans *= ara[n-1];
					}
				}
			}*/
			
			ans = ara[n-1] * ara[n-2] * ara[n-3] * ara[n-4] * ara[n-5];
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

