//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber

#include <bits/stdc++.h>

using namespace std;

// typedefs...
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

// constants...
const double PI = acos(-1);

// defines...
#define MP make_pair
#define PB push_back
#define FI first
#define SE second
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return ((ll)a*b/(ll)gcd(a, b));
}
ll comb(ll a, ll b)
{
    ll x = max(a-b, b), ans=1;

    for(ll K=a, L=1; K>=x+1; K--, L++){
        ans *= K;
        ans /= L;
    }

    return ans;
}
 

void task()
{
    //code here...
    
    string s;
    
    cin >> s;
    
    int n = s.length();
    set<char> ss;
	
	int q=0;
    for(int K=0; K<n; K++){
		if(s[K]=='?') q++;
		else ss.insert(s[K]);
	}
	
	
	if(n<26 || q+(int)ss.size()<26){
		cout << "-1\n";
		return;
	}
	
	
	bool f = 0;
	for(int K=0; K<n-25; K++){
		q = 0;
		ss.clear();
		
		for(int L=K; L<K+26; L++) {
			if(s[L]=='?') q++;
			else ss.insert(s[L]);
		}
		
		if(q+(int)ss.size()<26) continue;
		
		int i = K;
		for(int L=0; L<26; L++){
			auto it = ss.find(L+'A');
			if(it==ss.end()){
				for(int M=i; M<n; M++){
					if(s[M]=='?') {
						s[M] = L+'A';
						i = M + 1;
						ss.insert(L+'A');
						break;
					}
				}
			}
		}
		
		if((int)ss.size()==26){
			//cout << K << ' ' << s[K] << s[K+1] << s[K+2] << "\n";
			for(int L=0; L<n; L++){
				if(s[L]=='?') s[L] = 'A';
			}
			f = 1;
			break;
		}
	}
	
	if(!f) cout << "-1\n";
	else cout << s << "\n";
}
 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

