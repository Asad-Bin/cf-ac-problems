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

const int N = 3e5;
// int cnt1, cnt2, extra;
// int range_ans = 0;
// int block_size;

// struct Query{
//     int id, l, r;
    
//     Query() {}
//     Query(int _id, int _l, int _r){
//         id = _id;
//         l = _l;
//         r = _r;
//     }
    
//     bool operator<(Query &other) const{
//         int curr_size = l/block_size;
//         int other_size = other.l/block_size;
        
//         if(curr_size == other_size) return r < other.r;
//         return curr_size < other_size;
//     }
// } query[N+5];

// // multiset<int> ss;
// void add(ll x)
// {
//     // if(cnt[x]) range_ans -= cnt[x]*cnt[x]*x;
//     // if(cnt[x]) ss.erase(ss.find(cnt[x]));
//     // cnt[x]++;
//     // // range_ans += cnt[x]*cnt[x]*x;
//     // ss.insert(cnt[x]);

// 	if(x > 2) extra += x-2;

//     if(x == 1) cnt1++;
//     if(x == 2) cnt2++;
// }
// void rmv(ll x)
// {
//     // range_ans -= cnt[x]*cnt[x]*x;

//     // if(cnt[x]) ss.erase(ss.find(cnt[x]));
//     // cnt[x]--;
//     // if(cnt[x]) ss.insert(cnt[x]);
//     // if(cnt[x]) range_ans += cnt[x]*cnt[x]*x;


// }

// bool get_solution(int l, int r)
// {
// 	// cout << l << r << ": ";
// 	// for(auto it: ss) cout << it << ' ' ;
// 	// 	cout << "\n";

// 	// if(r-l+1 < *ss.rbegin()*2) return false;
// 	// return true;

// 	// cout << cnt1 << cnt2 << ' ' << extra << ' ' << l << ' ' <<r  << "\n";

// 	if(r == l) return false;

// 	if(cnt1)
	
// 	return true;
// }

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	cin >> t;
	for(int cs = 1; cs <= t; cs++){
		// cout << "Case " << cs << ": ";

		int n, q; cin >> n >> q;

		int ara[n];
		for(int K = 0; K < n; K++) cin >> ara[K];

		int cnt[n] = {0};
		if(ara[0] == 1) cnt[0] = 1;
		for(int K = 1; K < n; K++){
			if(ara[K] == 1) cnt[K] = 1;
			cnt[K] += cnt[K-1];

			ara[K] += ara[K-1];
		}
		// map<int, int> mp;
		// for(int K = 0; K < n; K++) mp[ara[K]]++;
		// int i = 1;
		// for(auto it: mp) mp[it.first] = i++;

		// for(int K = 0; K < n; K++) ara[K] = mp[ara[K]];

		for(int K = 0; K < q; K++){
			int a, b; cin >> a >> b; a--; b--;
			int l = a, r = b;

			if(l == r){
				cout << "NO\n";
				continue;
			}

			// query[K] = Query(K, a, b);

			int sum = ara[b] - (a ? ara[a-1] : 0);

			sum -= r-l+1;

			int val = cnt[r] - (l ? cnt[l-1] : 0);

			if((r-l+1)&1ll){
				if(sum >= val) cout << "YES\n";
				else cout << "NO\n";
			}
			else{
				if(sum >= val) cout << "YES\n";
				else cout << "NO\n";
			}
		}

		// block_size = sqrt(q);
		// sort(query, query+q);

		// int L = 0, R = -1;
	    // bool v[q];
	    // range_ans = 0;
	    // // ss.clear();
	    // // for(int K = 0; K <= n; K++) cnt[K] = 0;
	    // cnt1 = cnt2 = extra = 0;
	    
	    // for(int K = 0; K < q; K++){
	    //     int l = query[K].l;
	    //     int r = query[K].r;
	        
	    //     while(L < l){
	    //         rmv(ara[L]);
	    //         L++;
	    //     }
	    //     while(L > l){
	    //         L--;
	    //         add(ara[L]);
	    //     }
	    //     while(R < r){
	    //         R++;
	    //         add(ara[R]);
	    //     }
	    //     while(R > r){
	    //         rmv(ara[R]);
	    //         R--;
	    //     }
	        
	    //     v[query[K].id] = get_solution(l, r);
	    // }

	    // for(int K = 0; K < q; K++){
	    // 	if(v[K]) cout << "YES\n";
	    // 	else cout << "NO\n";
	    // }
	}

	return 0;
}





























