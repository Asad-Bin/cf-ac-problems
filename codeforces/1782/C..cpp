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
ll bigmod(ll a,ll b,ll mod){ if(b==0){ return 1;} ll tm=bigmod(a,b/2,mod); tm=(tm*tm)%mod; if(b%2==1) tm=(tm*a)%mod; return tm;}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		
		//int cnt[30] = {0};
		//for(int K = 0; K < n; K++){
			//cnt[s[K]-'a']++;
		//}
		
		//vector<int> v;
		////for(int K = 0; K < 26; K++) if(cnt[K]) v.push_back(cnt[K]);
		
		////int m = (int)v.size();
		////for(int K = 1; K < m; K++) v[K] += v[K-1];
		
		////sort(v.begin(), v.end());
		////int ara[m];
		////for(int K = 0; K < m; K++) ara[K] = v[K];
		////for(int K = 1; K < m; K++) ara[K] += ara[K-1];
		
		//int ans = n;
		//int op = 0;
		//for(int K = 1; K <= n; K++){
			//if(n % K != 0 || n/K > 26) continue;
			
			//int mid = 0;
			//v.clear();
			//int x = 0;
			//for(int L = 0; L < 26; L++){
				//if(cnt[L] >= K) x += cnt[L]-K;
				//else if(cnt[L]) v.push_back(cnt[L]);
			//}
			//mid = x;
			
			//sort(v.begin(), v.end());
			////debug(v);
			
			//while(!v.empty() && x){
				//if(K-v.back() <= x){
					//x -= K-v.back();
					//v.pop_back();
				//}
				//else{
					//v[(int)v.size()-1] += x;
					//x = 0;
					
					//break;
				//}
			//}
			////if(x) continue;
			
			////debug(mid);
			
			//int i = 0, j = (int)v.size()-1, a = 0;
			//while(i < j){
				//sort(v.begin()+i, v.begin()+j+1);
				
				//x = v[i++];
				////v.erase(v.begin());
				//a += x;
				
				//while(i <= j){
					//if(K-v[j] <= x){
						//x -= K-v[j--];
						////v.pop_back();
					//}
					//else {
						//v[j] += x;
						//x = 0;
						//break;
					//}
				//}
			//}
			
			//i = (int)v.size()-1;
			//j = 0;
			//int b = 0;
			//while(j < i){
				//sort(v.begin()+j, v.begin()+i+1);
				
				//x = v[i--];
				////v.erase(v.begin());
				//b += x;
				
				//while(j <= i){
					//if(K-v[j] <= x){
						//x -= K-v[j++];
						////v.pop_back();
					//}
					//else {
						//v[j] += x;
						//x = 0;
						//break;
					//}
				//}
			//}
			
			////debug(vector<int> {K, mid, ans});
			
			//mid += min(a, b);
			//if(mid < ans){
				//ans = mid;
				//op = K;
			//}
			////auto it = lower_bound(v.begin(), v.end(), K);
			////if(n % K != 0 || it == v.begin()) continue;
			
			////it--;
			////int i = it-v.begin();
			
			////int x = n/K - (n-i);
			////int mid = ara[i] - (i >= x ? ara[i-x] : 0);
			
			////ans = min(ans, n-(n-i)*K-mid);
		//}
		
		//cout << ans << "\n";
		
		//debug(op);
		//memset(cnt, 0, sizeof cnt);
		
		int ans = n;
		string a = s, sol;
		for(int M = 1; M <= n; M++){
			if(n % M != 0 || n/M > 26) continue;
			
			s = a;
			
			int cnt[30] = {0};
			for(int K = 0; K < n; K++){
				cnt[s[K]-'a']++;
			}
		
			int tot = 0;
			int x = n/M;
			vector<pair<int, int> > ara;
			for(int K = 0; K < 26; K++) {
				if(cnt[K]) ara.push_back({cnt[K], K});
			}
			sort(ara.rbegin(), ara.rend());
			while((int)ara.size() > x) ara.pop_back();
			while((int)ara.size() < x){
				for(int K = 0; K < 26; K++){
					if(cnt[K] == 0){
						ara.push_back({0, K});
						cnt[K] = 1;
						break;
					}
				}
			}
			
			memset(cnt, 0, sizeof cnt);
			for(int K = 0; K < n; K++) {
				bool ok = 0;
				for(int L = 0; L < x; L++){
					if(ara[L].second == s[K]-'a') ok = 1;
				}
				
				if(ok && cnt[s[K]-'a'] < M) cnt[s[K]-'a']++;
				else{
					s[K] = '.';
					tot++;
					//for(int L = (int)ara.size()-1; L >= 0; L--){
						//if(cnt[ara[L].second] < op){
							//cnt[ara[L].second]++;
							//s[K] = ara[L].second+'a';
							//break;
						//}
					//}
				}
			}
			
			for(int K = 0; K < x; K++) ara[K].first = cnt[ara[K].second];
			sort(ara.rbegin(), ara.rend());
			
			for(int K = 0; K < n; K++) {
				if(s[K] == '.') {
					for(int L = (int)ara.size()-1; L >= 0; L--){
						if(cnt[ara[L].second] < M){
							cnt[ara[L].second]++;
							s[K] = ara[L].second+'a';
							break;
						}
					}
				}
			}
			
			//for(int K = 0; K < n; K++){
				//if(cnt[s[K]-'a'] + 1 <= op) cnt[s[K]-'a']++;
				//else {
					//for(int L = 0; L < 26; L++){
						//if(cnt[L] < op){
							//cnt[L]++;
							//s[K] = L+'a';
							//break;
						//}
					//}
				//}
			//}
			
			if(tot < ans){
				ans = tot;
				sol = s;
			}
		}
		
		cout << ans << "\n" << sol << "\n";
	}
	
	return 0;
}





































