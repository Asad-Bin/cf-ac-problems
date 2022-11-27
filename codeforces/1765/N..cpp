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

void solve() {
	string s;
	ll k;
	cin >> s >> k;
	//ll bg = 0;
	vector<int> v[11];
	for(int i = 0; i < (int)s.size(); i++) {
		v[(int)(s[i] - '0')].push_back(i);
	}
	vector<char> ans;
	ll pos = k, bad = -1;
	for(int i = 1; i <= 9; i++) {
		if((int)v[i].size() && *v[i].begin() <= pos) {
			ans.push_back(s[*v[i].begin()]);
			k = k - (*v[i].begin() - bad - 1);
			bad = *v[i].begin();
			pos = min((ll)s.size(), *v[i].begin() + k + 1);
			break;
		}
	}
	while(pos < (int)s.size()) {
		
		for(int i = 0; i <= 9; i++) {
			int temp = lower_bound(v[i].begin(), v[i].end(), bad + 1) - v[i].begin();
			if( temp == (int)v[i].size() || v[i][temp] > pos ) continue;
			temp = v[i][temp];
			ans.push_back(s[temp]);
			k = k - (temp - bad - 1);
			bad = temp;
			pos = min((ll)s.size(), temp + k + 1);
			break; 
		}
		
	}
	for(int i = bad + 1; i < (int) s.size(); i++) {
		ans.push_back(s[i]);
		
	}
	//for(auto it : ans) cout << it << endl;
	for(int i = 0; i < (int)ans.size() - k; i++) cout << ans[i];
	cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	
	return 0;
}





































