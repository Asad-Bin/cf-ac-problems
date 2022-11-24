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
	
	int n; cin>> n;
	string s;
	 cin  >> s;
	
	string sol;
	sol.assign(n, '0');
	bool ok = 1;
	set<char> o, z;
	for(int K = 0; K < n; K++){
		if(o.upper_bound(s[K]) != o.end() && z.upper_bound(s[K]) != z.end()){
			ok = 0;
			break;
		}
		else if(o.upper_bound(s[K]) != o.end()){
			sol[K] = '0';
			z.insert(s[K]);
		}
		else if(z.upper_bound(s[K]) != z.end()){
			sol[K] = '1';
			o.insert(s[K]);
		}
		else{
			sol[K] = '0';
			z.insert(s[K]);
		}
	}
	
	if(ok) cout << "YES\n" << sol << "\n";
	else cout << "NO\n";
	
	return 0;
}





































