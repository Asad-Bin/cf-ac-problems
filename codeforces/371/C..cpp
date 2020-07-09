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

ll gcd(ll a, ll b) {
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


/*vector<int> primes;
vector<bool> mark(10000002);
void sieve()
{
	int n = 1e7+1;
    int i, j, limit = sqrt(n*1.) + 2;

    mark[1] = 1;

    for(i = 4; i<=n; i+=2) mark[i] = 1;

    primes.push_back(2);

    for(i = 3; i <= n; i += 2)
    {
        if(!mark[i])
        {
            primes.push_back(i);

            if(i<=limit)
            {
                for(j = i*i; j <= n; j += i*2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}*/

void task()
{
    //code here...
    
    string str;
    int b=0, s=0, c=0, nb, ns, nc, pb, ps, pc, cost;
    ll r, ans=0;
    const int INF = 1e9+5;
    
    cin >> str;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;
    
    for(int K=0; K<(int)str.length(); K++){
		if(str[K]=='B') b++;
		else if(str[K]=='S') s++;
		else c++;
	}
	
	ans = (ll)min(b?nb/b:INF, min(s?ns/s:INF, c?nc/c:INF));
	//cout << ans << "\n";
	nb -= ans*b;
	ns -= ans*s;
	nc -= ans*c;
	
	//cout << nb << ' ' << ns << ' ' << nc << "\n";
	
	while(1){
		if((!nb || !b) && (!ns || !s) && (!nc || !c)) break;
		
		cost = max(b-nb, 0)*pb + max(0, s-ns)*ps + max(0, c-nc)*pc;
		//cout << "cost = " << cost << "\n";
		if(cost && (ll)cost<=r){
			ans++;
			r -= (ll)cost;
			nb = max(0, nb-b);
			ns = max(0, ns-s);
			nc = max(0, nc-c);
		}
		else break;
	}
	
	cost = b*pb + s*ps + c*pc;
	
	//cout << "cost2 = " << cost << ' ' << r << "\n";
	
	if(cost) ans += (ll)r/cost;
	
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

