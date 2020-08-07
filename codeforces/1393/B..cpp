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
const ll INF = 1e18+5;

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


void task()
{
    //code here...
    
    // hoi  ekta  8 size er lagbe..
    // naile  duita  4  size  er  lagbe.
    // naile  ekta  4  and  duita  2 size  er lagbe.
    
    int n, x, q;
    char c;
    vi ara(100001), siz(1000001), save;
    
    cin >> n;
    for(int K=0; K<n; K++){
		cin >> x;
		ara[x]++;
		
		if(ara[x]>=8) save.PB(ara[x]);
	}
	
	for(int K=0; K<=100000; K++) siz[ara[K]]++;
	/*
	for(int K=1; K<=20; K++) cout << ara[K] << ' ';
	cout << "\n";
	for(int K=1; K<=20; K++) cout << siz[K] << ' ';
	cout << "\n";*/
	
	cin >> q;
	while(q--){
		cin >> c >> x;
		
		if(c=='-'){
			auto it = find(save.begin(), save.end(), ara[x]);
			if(it!=save.end()){
				save.erase(it);
			}
			
			ara[x]--;
			siz[ara[x]]++;
			siz[ara[x]+1]--;
		}
		else{
			ara[x]++;
			
			if(ara[x]>=8) save.PB(ara[x]);
			
			siz[ara[x]]++;
			siz[ara[x]-1]--;
		}
		
		
		if(sz(save)>0){
			cout << "YES\n";
		}
		else if(siz[4]>=2 || siz[5]>=2 || siz[6]>=2 || siz[7]>=2){
			cout << "YES\n";
		}
		else if(siz[4] && (siz[5] || siz[6] || siz[7])){
			cout << "YES\n";
		}
		else if(siz[5] && (siz[4] || siz[6] || siz[7])){
			cout << "YES\n";
		}
		else if(siz[6] && (siz[5] || siz[4] || siz[7])){
			cout << "YES\n";
		}
		else if(siz[7] && (siz[5] || siz[6] || siz[4])){
			cout << "YES\n";
		}
		else if((siz[4] || siz[5] || siz[6] || siz[7]) && (siz[3]>=2 || siz[2]>=2)){
			cout << "YES\n";
		}
		else if((siz[4] || siz[5] || siz[6] || siz[7]) && siz[3] && siz[2]){
			cout << "YES\n";
		}
		else if((siz[6] || siz[7]) && (siz[2] || siz[3])){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
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
