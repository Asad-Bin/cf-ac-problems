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
        ans = ans * K;
        ans /= L;
    }
 
    return ans;
}


bool func(pii a, pii b)
{
	if(a.se==b.se) return a.fi<b.fi;
	return a.se>b.se;
}
void task()
{
	// Code here.. ..
	
	int q, i = 1, x, m;
	set<pii> ss2, ss3;
	
	scanf("%d", &q);
	while(q--){
		scanf("%d", &x);
		
		if(x==1){
			scanf("%d", &m);
			
			ss2.insert(MP(i, m));
			ss3.insert(MP(m, i));
			
			i++;
		}
		else if(x==2){
			printf("%d ", ss2.begin()->fi);
			ss3.erase(MP(ss2.begin()->se, ss2.begin()->fi));
			ss2.erase(ss2.begin());
		}
		else if(x==3){
			//auto it = ss3.end();
			auto tr = ss3.end();
			--tr;
			//if(tr!=ss3.begin()) --tr;
			//--it;
			//while(1){
				//if(tr!=it && tr->fi==it->fi && tr!=ss3.begin()){
					//--it;
					//--tr;
				//}
				//else break;
			//}
			//if(it!=ss3.begin()) --it;
			
			auto it = ss3.lower_bound({tr->fi, 0});
			
			printf("%d ", it->se);
			ss2.erase(MP(it->se, it->fi));
			ss3.erase(it);
			
			//printf("%d ", ara[j].fi);
			//j++;
		}
	}
	printf("\n");
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
	
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	
	task();
 
    return 0;
}
