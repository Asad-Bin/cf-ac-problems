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
    return (a*b/gcd(a, b));
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
    
    int n, k, l, r;
    //string a="", b="";
    
    cin >> n;
    k = (int)n / 2;
    
    bool a[n], b[n];
    int ara1[n], ara2[n];
    
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    
    for(int K=0; K<n; K++){
		cin >> ara1[K] >> ara2[K];
	}
    
    for(int K=0; K<=k; K++){
		for(int L=0; L<K; L++) a[L] = 1;
		for(int L=0; L<K; L++) b[L] = 1;
		
		if(K!=0) continue;
		
		l = r = K;
		
		for(int L=1; L<=n-2*K; L++){
			if(ara1[l]<=ara2[r]){
				a[l] = 1;
				l++;
			}
			else{
				b[r] = 1;
				r++;
			}
		}
	}
	
	for(int K=0; K<n; K++) cout << a[K];
	cout << "\n";
	for(int K=0; K<n; K++) cout << b[K];
	cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}


