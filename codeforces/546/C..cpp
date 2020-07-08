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
    
    int n, k, x, y, ans=0;
    queue<int> f, s;
    
    cin >> n >> k;
    while(k--){
		cin >> x;
		f.push(x);
	}
	cin >> k;
	while(k--){
		cin >> x;
		s.push(x);
	}
	
	n *= 100;
	while(n--){
		if(f.empty()){
			cout << ans << ' ' << 2 << "\n";
			return;
		}
		else if(s.empty()){
			cout << ans << ' ' << 1 << "\n";
			return;
		}
		
		x = f.front();
		f.pop();
		y = s.front();
		s.pop();
		
		if(x>y){
			f.push(y);
			f.push(x);
		}
		else{
			s.push(x);
			s.push(y);
		}
		
		ans++;
	}
	
	cout << "-1\n";
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

