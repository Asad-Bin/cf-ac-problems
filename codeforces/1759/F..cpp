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
	
	
	int t; cin >> t;
	while(t--){
		int n, p; cin >> n >> p;
		
		set<int> ss;
		int ara[n+5];
		for(int K = 1 ;K <= n; K++){
			cin >> ara[K];
			ss.insert(ara[K]);
		}
		
		if(n == 1){
			ara[2] = ara[1];
			ara[1] = 0;
			//ss.insert(0);
			n++;
		}
		
		int l = 0, r = p-1, ans = p-1;
		while(l <= r){
			int cnt = (l+r)/2;
			int mid = (ara[n]+cnt)%p;
			
			//debug(vector<int>{l, r, ans, cnt, mid});
			
			bool ok = 1;
			if(mid == ara[n]){
				if(p != (int)ss.size()) ok = 0;
			}
			else if(mid > ara[n]){
				//int cnt = mid-ara[n]+1;
				
				if(p-1-mid+ara[n] > (int)ss.size()){
					ok = 0;
				}
				else{
					for(int K = mid+1; ok && K < p; K++) if(ss.find(K) == ss.end()) ok = 0;
					for(int K = 0; ok && K < ara[n]; K++) if(ss.find(K) == ss.end()) ok = 0;
				}
			}
			else{
				//int cnt = mid;
				
				if(ara[n]-1-mid  > (int)ss.size()){
					ok = 0;
				}
				else{
					int i = n-1, val = ara[n-1]+1;
					while(val == p){
						val = 0;
						i--;
						if(i == 0){
							val = 1;
							break;
						}
						val = ara[i] + 1;
					}
					for(int K = mid+1; ok && K < ara[n]; K++) if(K != val && ss.find(K) == ss.end()) ok = 0;
				}
			}
			
			if(ok) {
				ans =  min(ans, cnt);
				r = cnt-1;
			}
			else{
				l = cnt+1;
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}


























