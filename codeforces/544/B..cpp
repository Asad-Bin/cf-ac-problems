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
    
    int n, k;
    
    cin >> n >> k;
    
    string s[n];
    for(int K=0; K<n; K++){
		s[K] = "";
		for(int L=0; L<n; L++) s[K] += "S";
	}
	
	if(n==1){
		if(k==1) cout << "YES\nL\n";
		else if(k==0) cout << "YES\nS\n";
		else cout << "NO\n";
		return;
	}
	
	// handle n==1
	int cnt = 0;
	for(int K=0; K<n; K++){
		if(cnt==k) break;
		
		int L = 0;
		if(K&1) L = 1;
		for(; L<n; L++){
			if(cnt==k) break;
			
			if(K==0 && L==0 && s[K+1][L]=='S' && s[K][L+1]=='S'){
				s[K][L] = 'L';
				L++;
				cnt++;
			}
			else if(K==0 && L==n-1 && s[K+1][L]=='S' && s[K][L-1]=='S'){
				s[K][L] = 'L';
				L++;
				cnt++;
			}
			else if(K==n-1 && L==0 && s[K][L+1]=='S' && s[K-1][L]=='S'){
				s[K][L] = 'L';
				L++;
				cnt++;
			}
			else if(K==n-1 && L==n-1 && s[K][L-1]=='S' && s[K-1][L]=='S'){
				s[K][L] = 'L';
				L++;
				cnt++;
			}
			else if(K==0 && L!=0 && s[K][L+1]=='S' && s[K][L-1]=='S' && s[K+1][L]=='S'){
				s[K][L] = 'L';
				L++;
				cnt++;
			}
			else if(K!=0 && L==0 && s[K-1][L]=='S' && s[K][L+1]=='S' && s[K+1][L]=='S'){
				s[K][L] = 'L';
				L++;
				cnt++;
			}
			else if(K==n-1 && L!=n-1 && s[K][L+1]=='S' && s[K][L-1]=='S' && s[K-1][L]=='S'){
				s[K][L] = 'L';
				L++;
				cnt++;
			}
			else if(K!=n-1 && L==n-1 && s[K+1][L]=='S' && s[K][L-1]=='S' && s[K-1][L]=='S'){
				s[K][L] = 'L';
				L++;
				cnt++;
			}
			else if(s[K][L+1]=='S' && s[K][L-1]=='S' && s[K+1][L]=='S' && s[K-1][L]=='S'){
				s[K][L] = 'L';
				L++;
				cnt++;
			}
		}
	}
	
	if(cnt!=k) cout << "NO\n";
	else{
		cout << "YES\n";
		for(int K=0; K<n; K++) cout << s[K] << "\n";
	}
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

