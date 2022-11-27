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
	ll n, m;; cin>> n >> m;
	
	vector<ll> a(n);
	ll ans = 0;
	for(ll i = 0; i < n; i++){
		
		cin>> a[i];
		ans += a[i];
	}
	sort(a.begin(), a.end());
	
	ll i = 0, j = n-2; 
	
	ll cur = m- a[n-1];
	ll prv = n-1;
	
	bool f = 1;
	while(i <= j){
		if(f == 0){
			if(a[j] <= cur){
				cur = m - a[j];
				//cur += a[prv];
				//prv = j;
				f = 1;
				if(i == j){
					ans++;
					break;
				}
				j--;
			}else{
				
				ans++;
				cur = m;
				f = 0;
			
			}
		}else{
			if(a[i] <= cur){
				cur = m - a[i];
				//cur += a[prv];
				//prv = i;
				f = 0;
				if(i == j){
					ans++;
					break;
				}
				i++;
			}else{
				ans++;
				cur = m;
				f = 0;
			
			}
		}
		//cout << i << " " << j << " " << cur << " " << ans << endl;
		
	}
	cout << ans + (n == 1 ? 1 : 0)  << "\n";
	return 0;
}





































