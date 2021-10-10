#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<long long>
#define PB push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
//#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int MX = 2e5;
ll ara[MX+5];
map<ll, ll> mp;

ll get(ll n, ll sum)
{
	mp.clear();
	for(int K=0; K<n; K++){
		mp[ara[K]*n]++;
	}
	
	ll cnt = 0;
	
	for(int K=0; K<n; K++){
		cnt += mp[sum-ara[K]*n];
		
		if(sum-ara[K]*n == ara[K]*n) cnt--;
	}
	
	return cnt/2LL;
}
int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
	
	ll t, n;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		ll sum = 0;
		for(int K=0; K<n; K++){
			cin >> ara[K];
			sum += ara[K];
		}
		
		if(n==3){
			int cnt = 0;
			if(ara[0]*3 == sum) cnt++;
			if(ara[1]*3==sum) cnt++;
			if(ara[2]*3==sum) cnt++;
			
			cout << cnt << "\n";
			
			continue;
		}
		
		ll mid = sum*2LL;
		sum = sum-mid;
		
		cout << get(n, mid) << "\n";
	}
	
	return 0;
}














































