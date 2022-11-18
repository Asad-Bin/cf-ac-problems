// . . . Bismillahir Rahmanir Rahim . . .
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#ifndef ONLINE_JUDGE
#define dbg_out cout
#define dbg(...) dbg_out << "DBG )> "; __f(#__VA_ARGS__, __VA_ARGS__);
template<typename T1, typename T2> ostream& operator<<(ostream& out, pair<T1, T2> pr) { out << "{ " << pr.first << ", " << pr.second << " }"; return out; }
template<typename T1> ostream& operator<<(ostream& out, vector<T1> vec) { out << "{ "; for (auto &x: vec) out << x << ", "; out << "}"; return out; }
template<typename T1, size_t size> ostream& operator<<(ostream& out, array<T1, size> arr) { out << "{ "; for (auto &x: arr) out << x << ", "; out << "}"; return out; }
template<typename T1, typename T2> ostream& operator<<(ostream& out, map<T1, T2> mp) { out << "{ ";for (auto &x: mp) out << x.first << ": " << x.second <<  ", "; out << "}"; return out; }
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { while (isspace(name[0])) name++; (isalpha(name[0]) || name[0] == '_') ? dbg_out << name << ": " << arg1 << "\n" : dbg_out << arg1 << "\n"; dbg_out.flush();}
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) { const char *comma = strchr(names + 1, ','); while (isspace(names[0])) names++; (isalpha(names[0]) || names[0] == '_') ? dbg_out.write(names, comma - names) << ": " << arg1 << " | " : dbg_out << arg1 << " | "; __f(comma + 1, args...);}
#else
#define dbg(...)
#endif


const int N = 2e5;
ll ara[N+5];
int n;
int calc(int at, ll h, int g, int b)
{
	if(at == n) return 0;
	if(ara[at] < h) return calc(at+1, h+ara[at]/2, g, b) + 1;
	
	int ans = 0;
	if(g && ara[at] < h*2){
		ans = calc(at+1, h*2+ara[at]/2, g-1, b) + 1;
	}
	if(b && ara[at] < h*3){
		ans = max(ans, calc(at+1, h*3+ara[at]/2, g, b-1) + 1);
	}
	if(g == 2 && ara[at] < h*4){
		ans = max(ans, calc(at+1, h*4+ara[at]/2, g-2, b) + 1);
		//h *= 4;
		//h += ara[K]/2;
		//g -= 2;
		//ans++;
	}
	if(g && b && ara[at] < h*6){
		ans = max(ans, calc(at+1, h*6+ara[at]/2, g-1, b-1) + 1);
		//h *= 6;
		//h += ara[K]/2;
		//g--;
		//b--;
		//ans++;
	}
	if(g == 2 && b && ara[at] < h*12){
		ans = max(ans, calc(at+1, h*12+ara[at]/2, g-2, b-1) + 1);
		//h *= 12;
		//h += ara[K]/2;
		//g -= 2;
		//b--;
		//ans++;
	}
	
	return ans;
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	ll t; cin >> t;
	while(t--){
		ll h; cin >> n >> h;
		
		for(int K = 0; K < n; K++) cin >> ara[K];
		sort(ara, ara+n);
		
		int g = 2, b = 1;
		
		ll ans = calc(0, h, g, b);
		
		//ll ans = 0;
		//for(int K = 0; K < n; K++){
			//if(ara[K] < h){
				//h += ara[K]/2;
				//ans++;
			//}
			//else if(g && ara[K] < h*2){
				//h *= 2;
				//h += ara[K]/2;
				//g--;
				//ans++;
			//}
			//else if(b && ara[K] < h*3){
				//h *= 3;
				//h += ara[K]/2;
				//b--;
				//ans++;
			//}
			//else if(g == 2 && ara[K] < h*4){
				//h *= 4;
				//h += ara[K]/2;
				//g -= 2;
				//ans++;
			//}
			//else if(g && b && ara[K] < h*6){
				//h *= 6;
				//h += ara[K]/2;
				//g--;
				//b--;
				//ans++;
			//}
			//else if(g == 2 && b && ara[K] < h*12){
				//h *= 12;
				//h += ara[K]/2;
				//g -= 2;
				//b--;
				//ans++;
			//}
		//}
		
		cout << ans << "\n";
	}
	
	return 0;
}


























