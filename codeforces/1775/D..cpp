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



const ll N = 3e5;
vector<ll> ara[N+5], divs[N+5], primes;
vector<bool> mark(N+5);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	mark[1] = 1;
	for(ll K = 2; K <= N; K++){
		if(!mark[K]){
			primes.push_back(K);
			for(ll L = K*K; L <= N; L += K) mark[L] = 1;
		}
	}
	
	int n; cin >> n;
	ll in[n+1];
	for(int K = 1; K<= n; K++) cin >> in[K];
	
	int st, en; cin >> st >> en;
	
	for(int K = 1; K <= n; K++){
		for(int L = 0; L < (int)primes.size() && primes[L]*primes[L] <= in[K]; L++){
			if(in[K] % primes[L] == 0){
				while(in[K] % primes[L] == 0){
					in[K] /= primes[L];
				}
				ara[K].push_back(primes[L]);
				divs[primes[L]].push_back(K);
			}
		}
		if(in[K] > 1){
			ara[K].push_back(in[K]);
			divs[in[K]].push_back(K);
		}
	}
	
	
	
	vector<int> level(n+5, -1), par(n+5, -1), used(N+5);
	queue<int> q;
	q.push(st);
	level[st] = 0;
	bool ok = 1;
	while(ok && !q.empty()){
		int u = q.front();
		q.pop();
		
		for(int d:ara[u]){
			if(used[d]) continue;
			used[d] = 1;
			
			for(int node:divs[d]){
				if(level[node] == -1){
					level[node] = level[u] + 1;
					q.push(node);
					par[node] = u;
					
					if(node == en) {
						ok = 0;
						break;
					}
				}
			}
			if(!ok) break;
		}
	}
	
	int i = en;
	vector<int> v;
	v.push_back(i);
	while(i != st && i != -1){
		i = par[i];
		v.push_back(i);
	}
	
	if(i == -1){
		cout << -1 << "\n";
	}
	else{
		cout << (int)v.size() << "\n";
		reverse(v.begin(), v.end());
		for(auto it: v) cout << it << ' ';
		cout << "\n";
	}
	
	return 0;
}





































