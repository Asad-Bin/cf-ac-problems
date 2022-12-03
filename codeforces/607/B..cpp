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


int n;
const int N = 500;
const int inf = 1e9+7;
int ara[N+5], dp[N+5][N+5];
int calc(int l, int r)
{
	if(r < l) return 0;
	if(r == l) return 1;
	if(l+1 == r){
		if(ara[l] == ara[r]) return 1;
		return 2;
	}
	
	if(dp[l][r]  != -1) return dp[l][r];
	
	//if(ara[l] == ara[r]) return dp[l][r] = calc(l+1, r-1);
	
	int ans = calc(l+1, r) + 1;
	for(int K = l+2; K <= r; K++){
		if(ara[l] == ara[K]){
			ans = min(ans, calc(l+1, K-1)+calc(K+1, r));
		}
	}
	
	if(ara[l] == ara[l+1]) ans = min(ans, calc(l+2, r) + 1);
	
	debug(vector<int>{l, r, ans});
	return dp[l][r] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for(int K =0; K < n; K++) cin >> ara[K];
	
	memset(dp, -1, sizeof dp);
	cout << calc(0, n-1) << "\n";
	
	return 0;
}





































