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



const int MAX_N = 1e5+5;
string T, P;  // T = text, P = pattern
int b[MAX_N], n, m;       // b = back table, n = length of T, m = length of P
void kmpPreprocess() {    // call this before calling kmpSearch()
    int i = 1, j = 0;
    b[0] = 0;                                    // starting values
    while (i < m) {                               // pre-process the pattern string P
		while (j > 0 && P[i] != P[j]) j = b[j-1];  // different, reset j using b
		if(P[i] == P[j]) j++;       // if same, advance both pointers
		b[i] = j;  // observe i = 8, 9, 10, 11, 12, 13 with j = 0, 1, 2, 3, 4, 5
		i++;
    }
}  // in the example of P = "SEVENTY SEVEN" above
//int kmpSearch() {                                // this is similar as kmpPreprocess(), but on string T
    //int i = 0, j = 0, cnt = 0;                             // starting values
    //while (i < n) {                               // search through string T
		//while (j >= 0 && T[i] != P[j]) j = b[j];  // different, reset j using b
		//i++;
		//j++;           // if same, advance both pointers
		//if (j == m) {  // a match found when j == m
		  ////printf("P is found at index %d in T\n", i - j);
		  //cnt++;
		  //j = b[j];  // prepare j for the next possible match
		//}
    //}
//}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s; cin >> s;
	//n = 1+2*(int)s.length();
	//T = s + "#" + s;
	m = (int)s.length();
	P = s;
	kmpPreprocess();
	
	//for(int K = 0; K < m; K++) cout << b[K] << ' ';
	//cout << "\n";
	
	//vector<pair<int, int> > ara;
	//ara.push_back({n, 1});
	//for(int K = n; K > 0; K--){
		//m = K;
		//int cnt = kmpSearch();
	//}
	
	n = m;
	vector<int> ans(n + 1);
	for (int i = 0; i < n; i++)
		ans[b[i]]++;
	for (int i = n-1; i > 0; i--)
		ans[b[i-1]] += ans[i];
	for (int i = 0; i <= n; i++)
		ans[i]++;
		
	//for(int K = 0; K <= n; K++) cout << ans[K] << ' ' ;
	//cout << "\n";
	
	vector<pair<int, int> > v;
	int i = n;
	while(i){
		v.push_back({i, ans[i]});
		i = b[i-1];
	}
	
	cout << (int)v.size() << "\n";
	reverse(v.begin(), v.end());
	for(auto it:v) cout << it.first << ' ' << it.second << "\n";

	
	return 0;
}





































