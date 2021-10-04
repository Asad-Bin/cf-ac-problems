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


struct Node{
	int a, b, c, st, id, ans;
	
	Node() {}
	Node(int _a, int _b, int _c, int _st, int _id, int _ans){
		a = _a;
		b = _b;
		c = _c;
		st = _st;
		id = _id;
		ans = _ans;
	}
};

vector<Node> ara;
bool cmp0(Node a, Node b)
{
	if(a.c != b.c) return a.c < b.c;
	return a.b < b.b;
}
bool cmp1(Node* a, Node* b)
{
	return a->id < b->id;
}
bool cmp2(Node a, Node b)
{
	return a.id < b.id;
}
bool cmp3(Node a, Node b)
{
	return a.b < b.b;
}

const int MX = 1e5;
int bit[MX+5];
void add(int idx, int delta) {
	for(; idx < MX; idx = idx | (idx + 1))
		bit[idx] += delta;
}
ll sum(int r) {
	ll ret = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		ret += bit[r];
	return ret;
}
//ll sum(int l, int r) {
	//return sum(r) - sum(l - 1);
//}

void task()
{
	// Code here.. ..
	
	int n, a, b, c;
	
	cin >> n;
	
	for(int K=0; K<n; K++){
		cin >> a >> b >> c;
		
		ara.PB(Node(a, b, c, -1, K, -1));
	}
	
	sort(all(ara), cmp3);
	for(int K=0; K<n; K++){
		ara[K].st = K;
	}
	
	sort(all(ara), cmp0);
	
	int i = 0;
	vector<Node*> v;
	while(i < n){
		v.clear();
		Node x = ara[i];
		while(i < n && ara[i].c == x.c){
			v.PB(&ara[i]);
			i++;
		}
		
		sort(all(v), cmp1);
		
		//bit.assign(MX+2, 0);
		memset(bit, 0, sizeof bit);
		
		for(int K=0; K<sz(v); K++){
			Node* xxx = v[K];
			
			if(xxx->a == 1) add(xxx->st, 1);
			else if(xxx->a == 2) add(xxx->st, -1);
			else xxx->ans = sum(xxx->st);
		}
	}
	
	sort(all(ara), cmp2);
	for(auto x:ara){
		if(x.ans != -1) cout << x.ans << "\n";
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
















