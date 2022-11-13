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


const int N = 2e5;
//ll pre[N+5], tree[4*N+5];
//void build(int at, int l, int r)
//{
	//if(l == r){
		//tree[at] = pre[l-1];
		//return;
	//}
	
	//int mid = (l +r)/2;
	
	//build(at*2, l, mid);
	//build(at*2+1, mid+1, r);
	
	//tree[at] = tree[at*2] + tree[at*2+1];
//}
//void prop(int at)
//{
	//lazy[at*2] += lazy[at];
	//lazy[at*2+1] += lazy[at];
	//tree[at*2] += lazy[at];
	//tree[at*2+1] += lazy[at];
	
	//lazy[at] = 0;
	//tree[at] = tree[at*2] + tree[at*2+1];
//}
//ll query(int at, int l, int r, int L, int R)
//{
	//if(r < L || R < l) return 0;
	//if(L <= l && r <= R){
		//return tree[at];
	//}
	
	//prop(at);
	//int mid = (l +r)/2;
	
	//ll ans = query(at*2, l, mid, L, R);
	//ans += query(at*2+1, mid+1, r, L, R);
	
	//return ans;
//}
//void update(int at, int l, int r, int L, int R)
//{
	//;
//}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int ara[n];
		map<ll, ll > mp;
		
		ll sum = 0;
		for(int K = 0; K < n; K++){
			cin >> ara[K];
			//sum += ara[K];
		}
		
		ll ans = 0;
		sum = 0;
		ll mx = 0;
		bool ok = 1;
		for(int K = 0; K < n; K++){
			if(ara[K] == 0){
				if(ok) ans += mp[0];
				else ans += mx;
				
				mp.clear();
				sum = 0;
				mx = 1;
				ok = 0;
				mp[0]++;
			}
			else{
				sum += ara[K];
				mp[sum]++;
				
				mx = max(mx, mp[sum]);
			}
		}
		debug(mp);
		if(ok) ans += mp[0];
		else ans += mx;
		
		cout << ans << "\n";
	}
	
	return 0;
}


























