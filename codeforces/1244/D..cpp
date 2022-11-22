// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifndef ONLINE_JUDGE
#define good cout << "-----ok-----\n";
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
	
	int n; cin >> n;
	int col[4][n+5];
	ll mn = 1e18;
	vector<int> ans, v(n+5);
	for(int K = 1; K <= 3; K++){
		for(int L = 1; L <= n; L++){
			cin >> col[K][L];
		}
	}
	
	vector<int> ara[n+5];
	for(int K = 1; K < n; K++){
		int a, b;
		cin >> a >> b;
		
		ara[a].push_back(b);
		ara[b].push_back(a);
	}
	int node = -1, p = -1;
	for(int K = 1; K <= n; K++){
		if((int)ara[K].size() == 1){
			node = p = K;
			break;
		}
		else if((int)ara[K].size() > 2){
			cout << -1 << "\n";
			return 0;
		}
	}
	if(node == -1){
		cout << -1 << "\n";
		return 0;
	}
	//good;
	int nd = node;
	for(int K = 1; K <= 3; K++){
		for(int L = 1; L <= 3; L++){
			if(K != L){
				node = p = nd;
				v[node] = K;
				
				//good;
				//if((int)ara[node].size() > 1) {
					//cout << -1 << "\n";
					//return 0;
				//}
				if(ara[node][0] == p){
					p = node;
					node = ara[node][1];
				}
				else{
					p = node;
					node = ara[node][0];
				}
				v[node] = L;
				
				ll cost = 0;
				cost += col[K][p] + col[L][node];
				
				for(int M = 2; M < n; M++){
					if((int)ara[node].size() > 2){
						cout << -1 << "\n";
						return 0;
					}
					else if((int)ara[node].size() == 2 && ara[node][0] != p && ara[node][1] != p){
						cout << -1 << "\n";
						return 0;
					}
					
					int x = 1;
					if(ara[node][0] == p){
						x = ara[node][1];
					}
					else{
						x = ara[node][0];
					}
					
					if(v[node] != 1 && v[p] != 1) v[x] = 1, cost += col[1][x];
					else if(v[node] != 2 && v[p] != 2) v[x] = 2, cost += col[2][x];
					else if(v[node] != 3 && v[p] != 3) v[x] = 3, cost += col[3][x];
					
					p = node;
					node = x;
				}
				
				if(cost < mn){
					ans = v;
					mn = cost;
				}
			}
		}
	}
	
	cout << mn << "\n";
	for(int K = 1; K <= n; K++) cout << ans[K] << ' ';
	cout << "\n";
	
	
	return 0;
}





































