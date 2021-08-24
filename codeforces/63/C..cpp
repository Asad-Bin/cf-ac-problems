//...Bismillahir Rahmanir Rahim...
// ***Asad Bin Saber***

#include <bits/stdc++.h>
using namespace std;
 
// typedefs...
typedef long long            ll;
typedef unsigned long long   ull;
typedef pair<int, int>       pii;
typedef vector<int>          vi;
typedef vector<ll>           vl;
typedef pair<ll, ll>         pll;
 
// constants...
const double PI = acos(-1);
const int    mod = 1e9+7; // 998244353;
const int    MXI = 1e9+5;
const ll     MXL = 1e18+5;

// defines...
#define MP             make_pair
#define PB             push_back
#define fi             first
#define se             second
#define sz(x)          (int)x.size()
#define all(x)         begin(x), end(x)
#define si(a)          scanf("%d", &a)
#define sii(a, b)      scanf("%d%d", &a, &b)
#define siii(a, b, c)  scanf("%d%d%d", &a, &b, &c)
#define sl(a)          scanf("%lld", &a)
#define sll(a, b)      scanf("%lld%lld", &a, &b)
#define slll(a, b, c)  scanf("%lld%lld%lld", &a, &b, &c)
#define precise_impact cout<<setprecision(6)<<fixed;

// chess moves...
// int dx[] = {+0, +0, -1, +1}; ///Up-down, Left-Right
// int dy[] = {+1, -1, +0, +0};
// int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's Move
// int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
// int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2}; ///Knight's Move
// int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};

// structs...
struct hash_pair{ template <class T1, class T2> size_t operator()(const pair<T1, T2>& p) const{ auto hash1 = hash<T1>{}(p.first); auto hash2 = hash<T2>{}(p.second); return hash1 ^ hash2;}};

// functions...
ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll bigmod(ll a, ll p, ll M)
{
	// If 'M' is a prime number, then we can speed up it just by calculating "a^(p%(M-1))";
	p %= (M-1);
	ll result = 1LL;
	while(p>0LL){
		if(p&1LL) result = result * a % M;
		a = a * a % M;
		p>>=1LL;
	}
	return result;
}
ll inverse(ll a, ll M){
	if(gcd(a, M)==1) return bigmod(a, M-2, M) % M; // (ax)%M = 1
	return 1;
}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K % mod; ans = ans * inverse(L, mod) % mod;} return ans;}
ll egcd(ll a,ll b,ll &x,ll &y){
	if(a==0){
		x=0; y=1;
		return b;
	}
	ll x1,y1;
	ll d=egcd(b%a,a,x1,y1);
	x=y1-(b/a)*x1; y=x1;
	return d;
}
void pbin(int n)
{
	vector<int> vv;
	while(n){
		vv.PB(n%2);
		n >>= 1;
	}
	for(int K=sz(vv); K<=5; K++) vv.PB(0);
	reverse(all(vv));
	for(auto x:vv) cout << x;
	cout << "\n";
}


int bull(string s, string t)
{
	int x = 0;
	
	if(s[0] == t[0]) x++;
	if(s[1] == t[1]) x++;
	if(s[2] == t[2]) x++;
	if(s[3] == t[3]) x++;
	
	return x;
}
int cow(string s, string t)
{
	int x = 0;
	
	for(int K=0; K<4; K++){
		for(int L=0; L<4; L++){
			if(s[K]==t[L]){
				t[L] = '.';
				x++;
			}
		}
	}
	
	return x;
}
void task()
{
	// Code here . . .
	
	set<string> ss;
	string s, t;
	s.assign(4, '0');
	int p, q;
	
	for(s[0]='0'; s[0]<='9'; s[0]++){
		for(s[1]='0'; s[1]<='9'; s[1]++){
			if(s[0] == s[1]) continue;
			if(s[0]=='0' && s[1]=='0') continue;
			
			for(s[2]='0'; s[2]<='9'; s[2]++){
				if(s[2]==s[0] || s[2]==s[1]) continue;
				
				for(s[3]='0'; s[3]<='9'; s[3]++){
					if(s[3]==s[0] || s[3]==s[1] || s[3]==s[2]) continue;
					
					ss.insert(s);
				}
			}
		}
	}
	
	int n;
	cin >> n;
	while(n--){
		cin >> s >> p >> q;
		
		auto x = ss.begin();
		while(x != ss.end()){
			t = *x;
			int a = bull(t, s);
			int b = cow(t, s);
			
			//cout << s << "\n" << t << "\n" << a << ' ' << b << "\n";
			
			++x;
			if(a==p && (b-a)==q){
				continue;
			}
			ss.erase(t);
		}
	}
	
	if(sz(ss)==1) cout << *ss.begin() << "\n";
	else if(sz(ss)==0) cout << "Incorrect data\n";
	else cout << "Need more data\n";
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
















