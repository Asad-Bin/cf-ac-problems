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
const int MX = 2e5+5;
const ll INF = 1e18;

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
    
    int t;
    string s;
    
    cin >> t;
    while(t--){
		cin >> s;
		
		int n = s.length();
		
		if(n==2){
			cout << 0 << "\n";
			continue;
		}
		
		bool mark[10];
		memset(mark, 0, sizeof mark);
		
		for(int K=0; K<n; K++) mark[s[K]-48] = 1;
		
		vector<pair<char, char> > ara;
		for(int K=0; K<10; K++){
			if(!mark[K]) continue;
			for(int L=0; L<10; L++){
				if(!mark[L]) continue;
				ara.PB(MP(K+'0', L+'0'));
			}
		}
		
		ll ans = 0;
		for(int K=0; K<sz(ara); K++){
			ll cnt = 0;
			for(int L=0; L<n; L++){
				if(s[L]==ara[K].fi){
					for(int M=L+1; M<n; M++){
						if(s[M]==ara[K].se){
							L = M;
							cnt++;
							break;
						}
					}
				}
			}
			if(cnt>ans) ans = cnt;
		}
		
		vector<int> count(10);
		int mx = 0;
		for(int K=0; K<n; K++){
			count[s[K]-'0']++;
			mx = max(mx, count[s[K]-'0']);
		}
		
		if(n-mx<n-2*ans) cout << n-mx << "\n";
		else cout << ((ll)n-2*ans) << "\n";
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


