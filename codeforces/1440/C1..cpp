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
const ll MXL = 1e18+5;
 
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
#define all(x) x.begin(), x.end()
 
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


void task()
{
	// Code here...
	
	int t, n, m;
	string s[100];
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		for(int K=0; K<n; K++) cin >> s[K];
		
		int cnt = 0;
		vector<pii> ara;
		bool ok = 1;
		while(cnt<=n*m && ok){
			ok = 0;
			for(int K=0; K<n-1; K++){
				for(int L=0; L<m-1; L++){
					if(s[K][L]=='1' && s[K][L+1]=='1' && s[K+1][L]=='1' && s[K+1][L+1]=='1'){
						s[K][L] = '0';
						s[K+1][L+1] = '0';
						s[K][L+1] = '0';
						ara.PB(MP(K, L));
						ara.PB(MP(K+1, L+1));
						ara.PB(MP(K, L+1));
						L++;
						ok = 1;
					}
					else if(s[K][L]=='1' && s[K][L+1]=='1' && s[K+1][L]=='1'){
						s[K][L] = '0';
						s[K+1][L] = '0';
						s[K][L+1] = '0';
						ara.PB(MP(K, L));
						ara.PB(MP(K+1, L));
						ara.PB(MP(K, L+1));
						cnt++;
						L++;
						ok = 1;
					}
					else if(s[K][L]=='1' && s[K][L+1]=='1' && s[K+1][L+1]=='1'){
						s[K][L] = '0';
						s[K+1][L+1] = '0';
						s[K][L+1] = '0';
						ara.PB(MP(K, L));
						ara.PB(MP(K+1, L+1));
						ara.PB(MP(K, L+1));
						cnt++;
						L++;
						ok = 1;
					}
					else if(s[K][L]=='1' && s[K+1][L]=='1' && s[K+1][L+1]=='1'){
						s[K][L] = '0';
						s[K+1][L+1] = '0';
						s[K+1][L] = '0';
						ara.PB(MP(K, L));
						ara.PB(MP(K+1, L+1));
						ara.PB(MP(K+1, L));
						cnt++;
						L++;
						ok = 1;
					}
					else if(s[K][L+1]=='1' && s[K+1][L]=='1' && s[K+1][L+1]=='1'){
						s[K+1][L] = '0';
						s[K+1][L+1] = '0';
						s[K][L+1] = '0';
						ara.PB(MP(K+1, L));
						ara.PB(MP(K+1, L+1));
						ara.PB(MP(K, L+1));
						cnt++;
						L++;
						ok = 1;
					}
					else if(s[K+1][L]=='1' && s[K+1][L+1]=='1'){
						s[K+1][L] = '0';
						s[K+1][L+1] = '0';
						
						ara.PB(MP(K, L));
						ara.PB(MP(K, L+1));
						ara.PB(MP(K+1, L));
						
						ara.PB(MP(K, L));
						ara.PB(MP(K, L+1));
						ara.PB(MP(K+1, L+1));
						
						cnt += 2;
						L++;
						ok = 1;
					}
					else if(s[K][L+1]=='1' && s[K+1][L+1]=='1'){
						s[K+1][L+1] = '0';
						s[K][L+1] = '0';
						
						ara.PB(MP(K+1, L));
						ara.PB(MP(K, L));
						ara.PB(MP(K+1, L+1));
						
						ara.PB(MP(K+1, L));
						ara.PB(MP(K, L));
						ara.PB(MP(K, L+1));
						
						cnt += 2;
						L++;
						ok = 1;
					}
					else if(s[K][L+1]=='1' && s[K+1][L]=='1'){
						s[K+1][L] = '0';
						s[K][L+1] = '0';
						
						ara.PB(MP(K+1, L+1));
						ara.PB(MP(K, L));
						ara.PB(MP(K+1, L));
						
						ara.PB(MP(K+1, L+1));
						ara.PB(MP(K, L));
						ara.PB(MP(K, L+1));
						
						cnt += 2;
						L++;
						ok = 1;
					}
					else if(s[K][L]=='1' && s[K+1][L+1]=='1'){
						s[K][L] = '0';
						s[K+1][L+1] = '0';
						
						ara.PB(MP(K+1, L));
						ara.PB(MP(K, L+1));
						ara.PB(MP(K, L));
						
						ara.PB(MP(K+1, L));
						ara.PB(MP(K, L+1));
						ara.PB(MP(K+1, L+1));
						
						cnt += 2;
						L++;
						ok = 1;
					}
					else if(s[K][L]=='1'&& s[K+1][L]=='1'){
						s[K][L] = '0';
						s[K+1][L] = '0';
						
						ara.PB(MP(K+1, L+1));
						ara.PB(MP(K, L+1));
						ara.PB(MP(K, L));
						
						ara.PB(MP(K+1, L+1));
						ara.PB(MP(K, L+1));
						ara.PB(MP(K+1, L));
						
						cnt += 2;
						L++;
						ok = 1;
					}
					else if(s[K][L]=='1' && s[K][L+1]=='1'){
						s[K][L] = '0';
						s[K][L+1] = '0';
						
						ara.PB(MP(K+1, L));
						ara.PB(MP(K+1, L+1));
						ara.PB(MP(K, L));
						
						ara.PB(MP(K+1, L));
						ara.PB(MP(K+1, L+1));
						ara.PB(MP(K, L+1));
						
						cnt += 2;
						L++;
						ok = 1;
					}
					else if(s[K][L]=='1'){
						s[K][L] = '0';
						
						ara.PB(MP(K, L));
						ara.PB(MP(K+1, L));
						ara.PB(MP(K+1, L+1));
						
						cnt++;
						
						ara.PB(MP(K, L));
						ara.PB(MP(K, L+1));
						ara.PB(MP(K+1, L));
						
						ara.PB(MP(K, L));
						ara.PB(MP(K, L+1));
						ara.PB(MP(K+1, L+1));
						
						cnt += 2;
						L++;
						ok = 1;
					}
					else if(s[K][L+1]=='1' && L+1==m-1){
						s[K][L+1] = '0';
						
						ara.PB(MP(K, L+1));
						ara.PB(MP(K+1, L));
						ara.PB(MP(K+1, L+1));
						
						cnt++;
						
						ara.PB(MP(K, L));
						ara.PB(MP(K, L+1));
						ara.PB(MP(K+1, L));
						
						ara.PB(MP(K, L));
						ara.PB(MP(K, L+1));
						ara.PB(MP(K+1, L+1));
						
						cnt += 2;
						L++;
						ok = 1;
					}
					else if(s[K+1][L]=='1' && K+1==n-1){
						s[K+1][L] = '0';
						
						ara.PB(MP(K, L));
						ara.PB(MP(K+1, L));
						ara.PB(MP(K+1, L+1));
						
						cnt++;
						
						ara.PB(MP(K+1, L));
						ara.PB(MP(K, L+1));
						ara.PB(MP(K, L));
						
						ara.PB(MP(K+1, L));
						ara.PB(MP(K, L+1));
						ara.PB(MP(K+1, L+1));
						
						cnt += 2;
						L++;
						ok = 1;
					}
					else if(s[K+1][L+1]=='1' && K+1==n-1 && L+1==m-1){
						s[K+1][L+1] = '0';
						
						ara.PB(MP(K, L+1));
						ara.PB(MP(K+1, L));
						ara.PB(MP(K+1, L+1));
						
						cnt++;
						
						ara.PB(MP(K+1, L+1));
						ara.PB(MP(K, L));
						ara.PB(MP(K+1, L));
						
						ara.PB(MP(K+1, L+1));
						ara.PB(MP(K, L));
						ara.PB(MP(K, L+1));
						
						cnt += 2;
						L++;
						ok = 1;
					}
				}
			}
		}
		
			cout << sz(ara)/3 << "\n";
			for(int K=0; K<sz(ara); K+=3){
				cout << ara[K].fi+1 <<  ' ' << ara[K].se+1 << ' ';
				cout << ara[K+1].fi+1 << ' ' << ara[K+1].se+1 << ' ';
				cout << ara[K+2].fi+1 << ' ' << ara[K+2].se+1 << "\n";
			}
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
