// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif


struct Trie{
	const int A = 26;
	int N;
	
	vector<vector<int> > next;
	vector<int> cnt;
	
	Trie() : N(0) {
		node();
	}
	
	int node(){
		next.emplace_back(A, -1);
		cnt.emplace_back(0);
		
		return N++;
	}
	
	inline int get(char c){
		return c-'0';
	}
	
	inline void insert(string s){
		int cur = 0;
		for(char c : s){
			int to = get(c);
			if(next[cur][to] == -1) next[cur][to] = node();
			cur = next[cur][to];
		}
		cnt[cur]++;
	}
	
	inline int find(string s){
		int cur = 0;
		for(char c : s){
			int to = get(c);
			if(next[cur][to] == -1) return false;
			cur = next[cur][to];
		}
		return cnt[cur];
	}
	
	// Doesn't check for existance
	inline void erase(string s){
		int cur = 0;
		for(char c : s){
			int to =get(c);
			cur = next[cur][to];
		}
		if(cnt[cur]) cnt[cur]--;
	}
};


const int N = 5000;
const ll mod1 = 1e9+7;
const ll mod2 = 1e9+9;
const ll base = 29;

ll hash1[N+5], hash2[N+5], pow1[N+5], pow2[N+5], inv1[N+5], inv2[N+5];

ll bigmod(ll a, ll p, ll M)
{
    // If 'M' is a prime number, then we can speed up it just by calculating "a^(p%(M-1))";
	p %= (M-1);
	
    ll result = 1LL;
    while(p>0LL){
        if(p&1LL) result = result * a % M;
        a = a * a % M;
        p>>=1LL;
    }
    return result;
}
ll inverse(ll a, ll M){
    if(gcd(a, M)==1) return bigmod(a, M-2, M) % M; // (ax)%M = 1
    return 1;
}

string s;
bool check(int K, int L, int i, int j)
{
	ll x = (hash1[L]-(K ? hash1[K-1] : 0) + mod1)*inv1[K]%mod1;
	ll y = (hash1[j]-(i ? hash1[i-1] : 0) + mod1)*inv1[i]%mod1;
	
//	cout << K << ' ' << L << ' ' << i << ' ' << j << ' ' << x << ' ' << y << endl;
	//cout << s[K] << ' ' << s[L] << ' ' << s[i] << ' ' << s[j] << endl;
	if(x == y){
		x = (hash2[L]-(K ? hash2[K-1] : 0) + mod2)*inv2[K]%mod2;
		y = (hash2[j]-(i ? hash2[i-1] : 0) + mod2)*inv2[i]%mod2;
		
		return x == y;
	}
	
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> s;
	
	int n = (int)s.length();
	
	
	pow1[0] = pow2[0] = 1;
	for(int K = 1; K < n; K++) pow1[K] = pow1[K-1] * base % mod1;
	inv1[n-1] = inverse(pow1[n-1], mod1);
	for(int K = n-2; K >= 0; K--) inv1[K]  = inv1[K+1] * base % mod1;
	
	for(int K = 1; K < n; K++) pow2[K] = pow2[K-1] * base % mod2;
	inv2[n-1] = inverse(pow2[n-1], mod2);
	for(int K = n-2; K >= 0; K--) inv2[K]  = inv2[K+1] * base % mod2;
	
	
	hash1[0] = hash2[0] = (s[0]-'a'+1);
	for(int K = 1; K < n; K++){
		hash1[K] = hash1[K-1] + (s[K]-'a'+1)*pow1[K];
		hash1[K] %= mod1;
		
		hash2[K] = hash2[K-1] + (s[K]-'a'+1)*pow2[K];
		hash2[K] %= mod2;
	}
	
	
	
	
	
	
	int dp[n][n] = {0}, cnt[n+1] = {0};
	
	for(int K = 0; K < n; K++) {
		dp[K][K] = 1;
		cnt[1]++;
	}
	for(int K = 0; K < n-1; K++){
		if(s[K] == s[K+1]){
			dp[K][K+1] = 2;
			cnt[2]++;
		}
		else{
			dp[K][K+1] = 0;
			//cnt[1]++;
		}
	}
	int R, val;
	for(int K = 3; K <= n; K++){
		for(int L = 0; L+K-1 < n; L++){
			R = L + K -1;
			
			//cout << K << ' ' << L << endl;
			val = min(dp[L][L+K/2-1], dp[L+(K+1)/2][R]);
			if(!check(L, L+K/2-1, L+(K+1)/2, R)) val = 0;
			
			//cout << val << ' ' << dp[L+1][R-1] << "\n";
			if(s[L] == s[R] && val == 0 && dp[L+1][R-1]){
				dp[L][R] = 1;
				cnt[1]++;
			}
			else if(s[L] != s[R] || val == 0){
				dp[L][R] = 0;
			}
			else{
				dp[L][R] = val + 1;
				cnt[dp[L][R]]++;
			}
		}
	}
	
	//for(int K = 1; K <= n; K++) cout << cnt[K] << ' ';
	//cout << endl;
	for(int K = n-1; K >= 1; K--) cnt[K] += cnt[K+1];
	
	for(int K = 1; K <= n; K++) cout << cnt[K] << ' ';
	cout << endl;
	
	return 0;
}





































