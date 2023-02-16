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
	
	
	string s;
	
	int cnt[26] = {0};
	cin >> s;
	int n = (int)s.length();
	
	for(int K = 0; K < (int)s.length(); K++) cnt[s[K]-'a']++;
	
	int odd = 0;
	for(int K = 0; K < 26; K++){
		if(cnt[K]&1) odd++;
	}
	
	odd--;
	//while(odd--){
		//cout << "hi\n";
		for(int K = 0; K < 26; K++){
			if(cnt[K]&1){
				//debug(K);
				char c = 'a';
				int pos = -1;
				for(int L = 0; L < n; L++){
					if(s[L] != K+'a' && (cnt[s[L]-'a']&1)){
						if(s[L] >= c){
							c = s[L];
							pos = L;
						}
					}
				}
				//debug(c); debug(pos);
				
				if(pos == -1) continue;
				
				for(int L = 0; L < n; L++){
					if(s[L] == K+'a'){
						//cout << "hi]n";
						if(s[pos] < s[L]){
							cnt[s[L]-'a']--;
							cnt[s[pos]-'a']++;
							s[L] = s[pos];
						}
						else{
							cnt[s[L]-'a']++;
							cnt[s[pos]-'a']--;
							s[pos] = s[L];
						}
						
						break;
					}
				}
				
				//for(int L = 0; L < n; L++){
					//if(s[L] != K+'a' && (cnt[s[L]-'a']&1)){
						//s[K] = s[L];
						//cnt[s[K]-'a']--;
						//cnt[s[L]-'a']++;
						
						//break;
					//}
				//}
				
				//break;
			}
		}
//	}
	
	//cout << s << "\n";
	//for(int K = 0; K < 26; K++) cout << cnt[K] << ' ' ;
	//cout << "\n";
	
	int j = 0;
	s = "";
	int x = -1;
	while(j < 26){
		if(cnt[j] & 1){
			//string a = s;
			//reverse(a.begin(), a.end());
			//s += (j+'a');
			//s += a;
			x = j;
			
			//if(j >= 26) break;
			//continue;
			cnt[x]--;
			//break;
		}
		
		int mid = cnt[j]/2;
		
		while(mid--) s += j+'a';
		
		cnt[j] -= mid;
		
		//if(j >= 25 && x == -1){
			//string a = s;
			//reverse(a.begin(), a.end());
			//s += a;
			
			//break;
		//}
		
		j++;
	}
	
	string a = s;
	reverse(a.begin(), a.end());
	if(x != -1) s += (x+'a');
	s += a;
			
	cout << s << "\n";
	
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
