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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin  >> t;
	while(t--){
		int n; cin >> n;
		
		set<pair<int, pair<int, int > > > ss;
		
		int ara[n+1] = {0};
		ss.insert({n, {-1, n}});
		int i = 1;
		while(!ss.empty()){
			int len = ss.rbegin()->first, l = ss.rbegin()->second.first*(-1), r = ss.rbegin()->second.second;
			
			ss.erase(*ss.rbegin());
			
			if(len&1){
				if(l <= (l+r)/2-1) ss.insert({(l+r)/2-l, {-l, (l+r)/2-1}});
				if((l+r)/2+1 <= r) ss.insert({r-(l+r)/2, {-(l+r)/2-1, r}});
				ara[(l+r)/2] = i++;
			}else{
				if(l <= (l+r-1)/2-1) ss.insert({(l+r-1)/2-l, {-l, (l+r-1)/2-1}});
				if((l+r-1)/2+1 <= r) ss.insert({r-(l+r-1)/2, {-(l+r-1)/2-1, r}});
				ara[(l+r-1)/2] = i++;
			}
		}
		
		for(int K = 1; K <= n; K++) cout << ara[K] << ' ';
		cout << "\n";
	}
	
	return 0;
}





































