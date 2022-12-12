// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg_out cout
#define debug(...) dbg_out << "DBG )> "; __f(#__VA_ARGS__, __VA_ARGS__);
template<typename T1, typename T2> ostream& operator<<(ostream& out, pair<T1, T2> pr) { out << "{ " << pr.first << ", " << pr.second << " }"; return out; }
template<typename T1> ostream& operator<<(ostream& out, vector<T1> vec) { out << "{ "; for (auto &x: vec) out << x << ", "; out << "}"; return out; }
template<typename T1, size_t size> ostream& operator<<(ostream& out, array<T1, size> arr) { out << "{ "; for (auto &x: arr) out << x << ", "; out << "}"; return out; }
template<typename T1, typename T2> ostream& operator<<(ostream& out, map<T1, T2> mp) { out << "{ ";for (auto &x: mp) out << x.first << ": " << x.second <<  ", "; out << "}"; return out; }
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { while (isspace(name[0])) name++; (isalpha(name[0]) || name[0] == '_') ? dbg_out << name << ": " << arg1 << "\n" : dbg_out << arg1 << "\n"; dbg_out.flush();}
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) { const char *comma = strchr(names + 1, ','); while (isspace(names[0])) names++; (isalpha(names[0]) || names[0] == '_') ? dbg_out.write(names, comma - names) << ": " << arg1 << " | " : dbg_out << arg1 << " | "; __f(comma + 1, args...);}
#else
#define debug(...)
#endif

ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}
ll bigmod(ll a,ll b,ll mod){ if(b==0){ return 1;} ll tm=bigmod(a,b/2,mod); tm=(tm*tm)%mod; if(b%2==1) tm=(tm*a)%mod; return tm;}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}


const int N = 2e5;
bool vis[2][N+5];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
string s[2];
int n;
int black;
bool dfs(pair<int, int> u, pair<int, int> p, int cnt)
{
	vis[u.first][u.second] = 1;
	if(cnt == black) return true;
	
	bool ok = 0;
	for(int K = 0; K < 3; K++){
		pair<int, int> v = {u.first+dx[K], u.second+dy[K]};
		
		if(v.first >= 0 && v.first <= 1 && v.second < n && s[v.first][v.second] == 'B' && !vis[v.first][v.second]){
			if(v != p) ok |= dfs(v, u, cnt+1);
			if(ok) return ok;
		}
	}
	
	vis[u.first][u.second] = 0;
	return ok;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--){
		cin >> n;
		cin >> s[0] >> s[1];
		
		bool ok = 1;
		//for(int M = 0; M <= 1; M++){
			//for(int K = 0; K < n; K++){
				//int cnt = 0;
				//for(int L = 0; L < 4; L++){
					//pair<int, int> v = {M+dx[L], K+dy[L]};
					
					//if(v.first >= 0 && v.first <= 1 && v.second >= 0 && v.second < n && s[v.first][v.second] == 'B') cnt++;
				//}
				
				//if(K > 0 && K < n-1 && cnt <= 1) ok = 0;
				//else if((K == 0 || K == n-1) && cnt == 0) ok = 0;
			//}
		//}
		
		
		int cnt = 0, st = 2;
		for(int K = 0; K < n; K++){
			if(s[0][K] == 'W' || s[1][K] == 'W'){
				if(s[0][K] == 'B' && (K == n-1 || (K < n-1 && s[0][K+1] == 'B')) && (K == 0 || (K && s[0][K-1] == 'B'))){}
				else if(s[1][K] == 'B' && (K == n-1 || (K < n-1 && s[1][K+1] == 'B')) && (K == 0 || (K && s[1][K-1] == 'B'))){}
				else ok = 0;// cout << K << "hi\n";
				
				continue;
			}
			
			
				cnt++;
				if(K > 0 && cnt==1) st = (s[0][K-1] == 'B' ? 0 : 1);
			//}
			//else{
			
			if(K == n-1 || (K < n-1 && s[0][K+1] == 'B' && s[1][K+1] == 'B')) continue;
			
				int en = 2;
				if(K < n-1) en = (s[0][K+1] == 'B' ? 0 : 1);
				
				if(cnt % 2 == 0){
					if(st == en || st == 2 || en == 2){}
					else{
						ok = 0;
						//cout << st << ' ' << en << "\n";
						break;
					}
				}
				
				if(cnt % 2 == 1){
					if((st == 0 &&  en == 1) || (st == 1 && en == 0) || st == 2 || en == 2){}
					else {
						ok = 0;
						break;
					}
				}
				
				cnt = 0;
				st = 2;
			//}
		}
		int en = 2;
		if(cnt % 2 == 0){
			if(st == en || st == 2 || en == 2){}
			else{
				ok = 0;
			}
		}
		
		if(cnt % 2 == 1){
			if((st == 0 &&  en == 1) || (st == 1 && en == 0) || st == 2 || en == 2){}
			else {
				ok = 0;
			}
		}
		
		
		//black = 0;
		//for(int K = 0; K < 2; K++){
			//for(int L = 0; L < n; L++){
				//if(s[K][L] == 'B') black++;
				//vis[K][L] = 0;
			//}
		//}
		
		//bool ok = 0;
		//if(s[0][0] == 'B'){
			//ok |= dfs({0, 0}, {0, 0}, 1);
		//}
		
		
		//for(int K = 0; K < 2; K++){
			//for(int L = 0; L < n; L++){
				//vis[K][L] = 0;
			//}
		//}
		//if(!ok && s[1][0] == 'B'){
			//ok |= dfs({1, 0}, {1, 0}, 1);
		//}
		
		if(ok) cout <<"YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}





































