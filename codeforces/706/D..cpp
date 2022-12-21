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


struct trie{
	const int A = 2;
	int N;
	
	vector<vector<int> > next;
	vector<int> cnt;
	vector<int> val;
	
	trie() : N(0) {
		node();
	}
	
	int node(){
		next.emplace_back(A, 0);
		cnt.emplace_back(0);
		//val.emplace_back(-1);
		
		return N++;
	}
	
	inline int get(int x){
		return x;
	}
	
	inline void insert(int x){
		int cur = 0;
		for(int K = 29; K >= 0; K--){
			cnt[cur]++;
			int to = ((x&(1<<K)) ? 1 : 0);
			if(next[cur][to] == 0) next[cur][to] = node();
			cur = next[cur][to];
		}
		cnt[cur]++;
		//val[cur] = x;
	}
	// Doesn't check for existance
	inline void erase(int x){
		int cur = 0;
		for(int K = 29; K >= 0; K--){
			cnt[cur]--;
			int to = get(((x&(1<<K)) ? 1 : 0));
			cur = next[cur][to];
		}
		cnt[cur]--;
		//if(cnt[cur] == 0) val[cur] = 0;
	}
	
	inline int find(int x){
		int cur = 0, ans = 0;
		for(int K = 29; K >= 0; K--){
			int to = ((x&(1<<K)) ? 1 : 0);
			if(next[cur][to ^ 1] == 0 || cnt[next[cur][to ^1]] == 0){
			}
			else{
				ans |= (1<<K);
				to ^= 1;
			}
			//if(next[cur][to] != -1) cur = next[cur][to];
			//else 
			cur = next[cur][to];
		}
		return ans;
	}
	
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int m, x; cin >> m;
	char c;
	trie tree;
	tree.insert(0);
	
	for(int L = 0; L < m; L++){
		cin >> c;
		cin.ignore();
		cin >> x;
		
		debug(pair<char, int>{c, x});
		
		if(c == '+'){
			tree.insert(x);
		}
		else if(c == '-'){
			tree.erase(x);
		}
		else {
			int val = 0;
			for(int K = 29; K >= 0; K--){
				if(x&(1<<K));
				else val |= (1<<K);
			}
			
			debug(tree.find(val));
			cout << tree.find(x) << "\n";
		}
	}
	
	return 0;
}





































