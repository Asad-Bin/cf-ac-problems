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
    
    int p, q, l, r, a, b, ans=0;
    
    cin >> p >> q >> l >> r;
    vector<pii> z, x;
    
    for(int K=0; K<p; K++){
		cin >> a >> b;
		z.PB(MP(a, b));
	}
	for(int K=0; K<q; K++){
		cin >> a >> b;
		x.PB(MP(a, b));
	}
	
	for(int K=l; K<=r; K++){
		bool f = 0;
		for(int L=0; L<q; L++){
			for(int M=0; M<p; M++){
				//cout << K << ' ' << z[M].first << ' ' << z[M].second << "\n";
				//cout << K << ' ' << x[L].first << ' ' << x[L].second << "\n";
				if(z[M].second>=K+x[L].first && z[M].first<=K+x[L].second){
					ans++;
					f = 1;
					break;
				}
			}
			if(f) break;
		}
	}
	
	cout << ans << "\n";
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

