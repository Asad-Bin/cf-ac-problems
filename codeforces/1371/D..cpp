//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 30 06 2020

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
    
    int t, n, k;
    
    cin >> t;
    while(t--){
		cin >> n >> k;
		
		string s[n];
		for(int K=0; K<n; K++){
			s[K] = "";
			for(int L=0; L<n; L++) s[K]+="0";
		}
		
		if(k%n==0) cout << '0' << "\n";
		else cout << 2 << "\n";
		
		int p = 0, q = 0;
		for(int K=1; K<=k; K++){
			s[p][q] = '1';
			p++;
			q = (q+1) % n;
			if(p==n){
				p = p%n;
				q = (q+1)%n;
			}
		}
		
		for(int K=0; K<n; K++){
			cout << s[K] << "\n";
		}
	}
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

