//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 02 07 2020

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
    
    int t, n, m;
    
    cin >> t;
    while(t--){
		cin >> n >> m;
		vector<vi> ara(n, vi (m));
		for(int K=0; K<n; K++){
			for(int L=0; L<m; L++) cin >> ara[K][L];
		}
		
		bool f = 0;
		for(int K=0; K<n; K++){
			for(int L=0; L<m; L++){
				int cnt = 0;
				/*if(L>0 && ara[K][L-1]!=0) cnt++;
				else if(K>0 && ara[K-1][L]) cnt++;
				else if(L<m-1 && ara[K][L+1]) cnt++;
				else if(K<n-1 && ara[K+1][L]) cnt++;*/
				
				if(K==0 && L==0) cnt=2;
				else if(K==n-1 && L==m-1) cnt=2;
				else if(K==0 && L==m-1) cnt=2;
				else if(L==0 && K==n-1) cnt=2;
				else if(K==0 || L==0) cnt=3;
				else if(K==n-1 || L==m-1) cnt=3;
				else cnt = 4;
				
				if(ara[K][L]>cnt){
					cout << "NO\n";
					f = 1;
					break;
				}
				
				ara[K][L] = cnt;
			}
			if(f) break;
		}
		
		if(!f){
			cout << "YES\n";
			for(int K=0; K<n; K++){
				for(int L=0; L<m; L++){
					cout << ara[K][L] << ' ';
				}
				cout << "\n";
			}
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

