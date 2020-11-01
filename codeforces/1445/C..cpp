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
 

vector<int> primes;
vector<bool> mark(1000002);
void sieve(int n)
{
    int i, j, limit = sqrt(n*1.) + 2;

    mark[1] = 1;

    for(i = 4; i<=n; i+=2) mark[i] = 1;

    primes.push_back(2);

    for(i = 3; i <= n; i += 2)
    {
        if(!mark[i])
        {
            primes.push_back(i);

            if(i<=limit)
            {
                for(j = i*i; j <= n; j += i*2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}
vector<pair<int, int> > divisors;
void divs(int n) {
	int cnt, tot=1, i;
	
	for(i=0; i<(int)primes.size() && (primes[i]*primes[i])<=n; i++) {
		if(n%primes[i]==0) {
			cnt=1;
			
			while(n%primes[i]==0) {
				n /= primes[i];
				cnt++;
			}
			
			divisors.push_back(make_pair(primes[i], cnt-1));
			tot*=cnt;
		}
	}
	
	if(n>1) {
		tot*=2;
		divisors.push_back(make_pair(n, 1));
	}
}
void task()
{
	// Code here...
	
	ll t, p, q, mn, save;
	sieve(1000000);
	
	cin >> t;
	while(t--){
		cin >> p >> q;
		
		divisors.clear();
		divs(q);
		save = p;
		//for(auto it:divisors) cout << it.fi << ' ' << it.se << "\n";
		
		int i = 0, n = sz(divisors);
		bool ok = 0;
		mn = MXL;
		
		while(i<n){
			int cnt = 0;
			while(p%divisors[i].fi==0){
				cnt++;
				p /= divisors[i].fi;
			}
			
			if(divisors[i].se>cnt){
				ok = 1;
				break;
			}
			else{
				ll tot = 1LL;
				for(int K=divisors[i].se; K<=cnt; K++) tot *= divisors[i].fi;
				mn = min(mn, tot);
				//cout << tot << ' ' << mn << ' ' << cnt << "\n";
			}
			
			i++;
		}
		
		if(ok) cout << save << "\n";
		else cout << save/mn << "\n";
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
