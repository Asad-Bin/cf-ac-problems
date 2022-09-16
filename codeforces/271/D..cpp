// . . . Bismillahir Rahmanir Rahim . . .

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#ifdef local
     #define debug(x) cerr << '{' << #x << " = " << (x) << '}' << "\n";
#else
    #define debug(x) // lol ojs
#endif


const ll base = 31;
const ll mod_1 = 1e9+7;
const ll mod_2 = 1e9+9;
int main()
{
	string s, good;
	int k;
	
	cin >> s >> good >> k;
	
	int n = (int)s.length();
	set<pair<pair<ll, ll>, ll > > ss;
	
	for(int K = 0; K < n; K++){
		ll hash_1 = 0, hash_2 = 0, i_1 = 1, i_2 = 1, cnt = 0;
		for(int L = K; L < n; L++){
			if(good[s[L]-'a'] == '0') cnt++;
			if(cnt > k) break;
			
			hash_1 = hash_1 + ((s[L]-'a'+1)*i_1%mod_1);
			hash_1 %= mod_1;
			
			hash_2 = hash_2 + ((s[L]-'a'+1)*i_2%mod_2);
			hash_2 %= mod_2;
			
			ss.insert({{hash_1, hash_2}, L-K+1});
			
			i_1 = i_1 * base % mod_1;
			i_2 = i_2 * base % mod_2;
		}
	}
	
	cout << (int)ss.size() << "\n";
	
	
	return 0;
}
