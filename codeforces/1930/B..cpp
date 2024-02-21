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


vector<int> primes;
vector<bool> mark(100002);
void sieve(int n)
{
    int i, j, limit = sqrt(n*1.) + 2;

    mark[1] = 1;

    for(i = 4; i<=n; i+=2) mark[i] = 1;

    primes.push_back(2);

    for(i = 3; i <= n; i += 2)
    {
            if(!mark[i])
            {
             primes.push_back(i);

              if(i<=limit)
               {
                    for(j = i*i; j <= n; j += i*2)
                    {
                            mark[j] = 1;
                    }
               }
            }
    }
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	sieve(1e5);

	int t = 1; 
	cin >> t;
	for(int cs = 1; cs <= t; cs++){
		// cout << "Case " << cs << ": ";

		int n; cin >> n;

		int ara[n+5], i = 1, used[n+5] = {0};

		ara[i] = 1;
		i++;

		// vector<int> v;
		// for(auto it: primes){
		// 	if(it > n) break;
		// 	// ara[i++] = it;
		// 	v.push_back(it);
		// 	used[it] = 1;
		// }
		// reverse(v.begin(), v.end());
		// for(auto it: v) ara[i++] = it;
		// reverse(v.begin(), v.end());

		// int mul = 2;
		// while(i <= n && mul < n){
		// 	set<int> xx;
		// 	for(auto it: v){
		// 		if(it*mul > n) break;

		// 		if(!used[it*mul]) xx.insert(it*mul);
		// 		used[it*mul] = 1;

		// 	}

		// 	// v.clear();
		// 	vector<int> vv;
		// 	for(auto it: xx) vv.push_back(it);
		// 	if(mul&1) reverse(vv.begin(), vv.end());
		// 	for(auto it: vv) if(i <= n) ara[i++] = it;
		// 	if(mul&1) reverse(vv.begin(), vv.end());

		// 	mul++;
		// }

		int x = 2, y = n;
		while(i <= n){
			if(i&1) ara[i++] = x++;
			else ara[i++] = y--;
		}

		for(int K = 1; K <= n; K++) cout << ara[K] << ' ';
		cout << "\n";
	}

	return 0;
}





























