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
ll bigmod(ll a,ll b,ll mod){ 
	b %= (mod-1);
	a %= mod;

	if(b==0){
	 return 1;
	} 
	ll tm=bigmod(a,b/2,mod); 
	tm=(tm*tm)%mod; 
	if(b%2==1) tm=(tm*a)%mod; 
	return tm;
}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}


#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	cin >> t;
	for(int cs = 1; cs <= t; cs++){
		// cout << "Case " << cs << ": ";

		int n; cin >> n;
		int ara[n+1], p[n+1];
		p[0] = ara[0] = 0; 
		for(int K = 1; K <= n; K++) cin >> ara[K];
		for(int K = 1; K <= n; K++) cin >> p[K];

		priority_queue<pair<int, int> > pq;
		for(int K = 1; K <= n; K++) pq.push({ara[K], K});

		int ans = 0, sum = 0, cnt = 0;
		int mn = 0;
		set<int> ss;
		while(!pq.empty()){
			int x = pq.top().first, i = pq.top().second;
			pq.pop();

			if(ara[i] == 0) continue;
			int temp = sum;
			sum = x;
			ss.insert(i);
			cnt++;

			// cout << x << ' ' << i << ' ' << cnt << ' ' << sum << "\n";
			// for(auto it: ss) cout << it << " ";
			// 	cout << "\n";


			if(ss.find(p[cnt-1]) != ss.end()){
				ss.erase(p[cnt-1]);
				// sum -= ara[p[cnt-1]];
				if(p[cnt-1] == i) sum = temp;
				cnt--;
			}
			ara[p[cnt]] = 0;

			// ans = max(ans, cnt*sum);
			if(cnt*sum > ans){
				ans = cnt*sum;
				mn = cnt;
			}
			else if(cnt*sum == ans) mn = min(cnt, mn);
			// cout << cnt << ' ' << sum << ' ' << ans << "\n";
		}

		cout << ans << ' ' << mn << "\n";
	}

	return 0;
}





























