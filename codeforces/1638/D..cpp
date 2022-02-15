// . . . Bismillahir Rahmanir Rahim . . .

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
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
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
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


int ara[1001][1001];

int check(int K, int L, int n, int m)
{
	if(K+1 > n || L+1 > m || K < 1 || L < 1) return 0;
	if(ara[K][L] == 0 && ara[K][L] == ara[K+1][L] && ara[K][L] == ara[K][L+1] && ara[K][L] == ara[K+1][L+1]) return 0;
	
	set<int> ss;
	ss.insert(ara[K][L]);
	ss.insert(ara[K][L+1]);
	ss.insert(ara[K+1][L]);
	ss.insert(ara[K+1][L+1]);

	if((int)ss.size() == 1 && *ss.begin() != 0){
		ara[K][L] = ara[K+1][L] = ara[K][L+1] = ara[K+1][L+1] = 0;
	}
	else if((int)ss.size() == 2 && *ss.begin()==0){
		ara[K][L] = ara[K+1][L] = ara[K][L+1] = ara[K+1][L+1] = 0;
	}
	else{
		return 0;
	}
	
	return *ss.rbegin();
}

int main()
{
	#ifdef LOCAL
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
	
    int n, m;
    
    cin >> n >> m;
    
    for(int K = 1; K <= n; K++){
		for(int L = 1; L <= m; L++) cin >> ara[K][L];
	}
	
	
	vector<pair<pair<int, int>, int> > sol;
	queue<pair<pair<int, int>, int> > v;
	set<int> ss;
	int num;
	bool ok = 1;
	
	//while(ok){
		//ok = 0;
		for(int K = n; K >= 1; K--){
			for(int L = m; L >= 1; L--){
				//if(K+1 <= n && L+1 <= m){
					//if(ara[K][L] == 0 && ara[K][L] == ara[K+1][L] && ara[K][L] == ara[K][L+1] && ara[K][L] == ara[K+1][L+1]) continue;
					
					//ss.clear();
					//ss.insert(ara[K][L]);
					//ss.insert(ara[K][L+1]);
					//ss.insert(ara[K+1][L]);
					//ss.insert(ara[K+1][L+1]);
					
					//if((int)ss.size() == 1 && *ss.begin() != 0){
						//ara[K][L] = ara[K+1][L] = ara[K][L+1] = ara[K+1][L+1] = 0;
						//v.push_back({{K, L}, *ss.begin()});
						//ok = 1;
					//}
					//else if((int)ss.size() == 2 && *ss.begin()==0){
						//ara[K][L] = ara[K+1][L] = ara[K][L+1] = ara[K+1][L+1] = 0;
						//v.push_back({{K, L}, *ss.rbegin()});
						//ok = 1;
					//}
					
					num = check(K, L, n, m);
					if(num){
						v.push({{K, L}, num});
					}
					
					//if(ara[K][L] && ara[K][L] == ara[K+1][L] && ara[K][L] == ara[K][L+1] && ara[K][L] == ara[K+1][L+1]){
						//v.push_back({{K, L}, ara[K][L]});
						//ara[K][L] = ara[K+1][L] = ara[K][L+1] = ara[K+1][L+1] = 0;
					//}
				//}
			}
		}
	//}
	
	
	int dx[]={0,0,1,1,1,-1,-1,-1};
	int dy[]={-1,1,0,1,-1,0,1,-1};
	
	while(!v.empty()){
		auto x = v.front();
		v.pop();
		sol.PB(x);
		
		for(int K = 0; K < 8; K++){
			//if(x.first.first+dx[K] <= n && x.first.first+dx[K] >= 1){
				//if(x.first.second+dy[K] <= m && x.first.second+dy[K] >= 1){
					num = check(x.first.first+dx[K], x.first.second+dy[K], n, m);
					if(num){
						v.push({{x.first.first+dx[K], x.first.second+dy[K]}, num});
					}
				//}
			//}
		}
	}
	
	
	
	ok = 1;
	for(int K = 1; K <= n; K++){
		for(int L = 1; L <= m; L++){
			if(ara[K][L] != 0) ok = 0;
		}
	}
	
	if(!ok){
		cout << "-1\n";
		return 0;
	}
	
	//bool ok = 1;
	//while(ok){
		//ok = 0;
		//for(int K = 1; K <= n; K++){
			//for(int L = 1; L <= m; L++){
				//if(K+1 <= n && L+1 <= m && ara[K][L] == ara[K+1][L] && ara[K][L] == ara[K][L+1] && 0 == ara[K+1][L+1]){
					//ara[K][L] = ara[K+1][L] = ara[K][L+1] = 0;
					//v.push_back({{K, L}, ara[K][L]});
					//ok = 1;
				//}
			//}
		//}
		//for(int K = 1; K <= n; K++){
			//for(int L = 1; L <= m; L++){
				//if(K+1 <= n && L+1 <= m && ara[K][L] == ara[K+1][L] && 0 == ara[K][L+1] && ara[K][L] == ara[K+1][L+1]){
					//ara[K][L] = ara[K+1][L] = ara[K+1][L+1] = 0;
					//v.push_back({{K, L}, ara[K][L]});
					//ok = 1;
				//}
			//}
		//}
		//for(int K = 1; K <= n; K++){
			//for(int L = 1; L <= m; L++){
				//if(K+1 <= n && L+1 <= m && 0 == ara[K+1][L] && ara[K][L] == ara[K][L+1] && ara[K][L] == ara[K+1][L+1]){
					//ara[K][L] = ara[K+1][L+1] = ara[K][L+1] = 0;
					//v.push_back({{K, L}, ara[K][L]});
					//ok = 1;
				//}
			//}
		//}
	//}
	
	
	//for(int K = 1; K <= n; K++){
		//for(int L = 1; L <= m; L++){
			//if(K+1 <= n && L+1 <= m && ara[K][L] == ara[K+1][L]){
				//ara[K][L] = ara[K+1][L] = 0;
					//v.push_back({{K, L}, ara[K][L]});
			//}
		//}
	//}
	//for(int K = 1; K <= n; K++){
		//for(int L = 1; L <= m; L++){
			//if(K+1 <= n && L+1 <= m && ara[K][L] == ara[K][L+1]){
				//ara[K][L] = ara[K][L+1] = 0;
					//v.push_back({{K, L}, ara[K][L]});
			//}
		//}
	//}
	
	
	//for(int K = 1; K <= n; K++){
		//for(int L = 1; L <= m; L++){
			//if(K+1 <= n && L+1 <= m && ara[K][L] == ara[K+1][L]){
				//ara[K][L] = 0;
					//v.push_back({{K, L}, ara[K][L]});
			//}
		//}
	//}
	
	cout << (int)sol.size() << "\n";
	for(int K = (int)sol.size()-1; K >= 0; K--) cout << sol[K].first.first << ' ' << sol[K].first.second << ' ' << sol[K].second << "\n";
	
	
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}
