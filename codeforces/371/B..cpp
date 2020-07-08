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
    
    int a, b, ans=0;
    
    cin >> a >> b;
    
    int a2=0, a3=0, a5=0;
    while(1){
		if(a%5==0){
			a5++;
			a /= 5;
		}
		else if(a%3==0){
			a3++;
			a /= 3;
		}
		else if(a%2==0){
			a2++;
			a /= 2;
		}
		else break;
	}
	
	int b2=0, b3=0, b5=0;
	while(1){
		if(b%5==0){
			b5++;
			b /= 5;
		}
		else if(b%3==0){
			b3++;
			b /= 3;
		}
		else if(b%2==0){
			b2++;
			b /= 2;
		}
		else break;
	}
	
	if(a!=b) cout << "-1\n";
	else cout << abs(a2-b2)+abs(a3-b3)+abs(a5-b5) << "\n";
}
 

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

