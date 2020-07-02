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
    
    int n, x1, x2, y1, y2, a, b, r, dis;
    
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    vector<pii> ara;
    
    for(int K=min(y1, y2); K<=max(y1, y2); K++){
		ara.PB(MP(x1, K));
		ara.PB(MP(x2, K));
	}
	for(int K=min(x1, x2)+1; K<max(x1, x2); K++){
		ara.PB(MP(K, y1));
		ara.PB(MP(K, y2));
	}
	
	while(n--){
		cin >> a >> b >> r;
		
		for(int K=0; K<(int)ara.size(); K++){
			dis = (ara[K].first-a)*(ara[K].first-a) + (ara[K].second-b)*(ara[K].second-b);
			if(dis<=r*r){
				ara.erase(ara.begin()+K);
				K--;
			}
		}
	}
	
	cout << ara.size() << "\n";
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

