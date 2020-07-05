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
    
    int t, n;
    
    cin >> t;
    while(t--){
		cin >> n;
		vi ara(n), mark(n+1), v;
		for(int K=0; K<n; K++){
			cin >> ara[K];
			mark[ara[K]]++;
		}
		vector<bool> unmark(n);
		
		int ans=0, mex, p=2*n;
		for(int K=0; K<n; K++){
			if(ara[K]==K) unmark[K] = 1;
		}
		
		while(1){
			for(int K=0; K<=n; K++){
				if(mark[K]==0){
					mex = K;
					break;
				}
			}
				
			if(mex==n){
				for(int K=0; K<n; K++){
					if(unmark[K]==0){
						mark[ara[K]]--;
						mark[mex]++;
						ara[K] = mex;
						v.PB(K+1);
						break;
					}
				}
			}
			else{
				mark[ara[mex]]--;
				ara[mex] = mex;
				mark[mex]++;
				unmark[mex] = 1;
				v.PB(mex+1);
			}
			
			//ans++;
			
			bool f = 0;
			for(int K=1; K<n; K++){
				if(ara[K]<ara[K-1]){
					f = 1;
					break;
				}
			}
			if(!f) break;
		}
		
		cout << (int)v.size() << "\n";
		if((int)v.size()==0){
			cout << "\n";
			continue;
		}
		for(int K=0; K<(int)v.size(); K++) cout << v[K] << ' ';
		cout << "\n";
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

