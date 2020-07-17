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
#define fi first
#define se second
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return (a/gcd(a, b)*b);
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
    
    int t, n;
    
    cin >> t;
    
    while(t--){
		cin >> n;
		
		int ara[n], pre = 0;
		for(int K=0; K<n; K++) cin >> ara[K];
		
		int save  = -1;
		//bool f  =0;
		for(int K=n-1; K>=0; K--){
			//if(ara[K]!=ara[K-1]) f = 1;
			if(K==0 && ara[K]>=ara[K+1]) {
				save = K;
				break;
			}
			else if(K==n-1 && ara[K]>ara[K-1]) {
				save = K;
				break;
			}
			else if(K>1 && K<n-1 && ara[K]>=ara[K+1] && ara[K]>ara[K-1]){
				save = K;
				break;
			}
		}
		
		if(save==-1){
			for(int K=1; K<n-1; K++){
				if(ara[K]<ara[K-1] && ara[K]<ara[K+1]) pre = K;
			}
		}
		else{
			for(int K=1; K<n-1; K++){
				if(K<save && ara[K]<ara[K-1] && ara[K]<=ara[K+1]) pre = K;
				else if(K>save && ara[K]<=ara[K-1] && ara[K]<ara[K+1]) pre = K;
			}
		}
		
		cout << pre << "\n";
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


