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


const int M = 1073741824;

vector<int> primes;
vector<bool> mark(1000002);

void sieve(int n)
{
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
}
int divisors(int t)
{
	int n = t, ans = 1, mid = 1, i=0;
	while(1){
		if(n==1) break;
		
		if(n%primes[i]==0){
			mid++;
			n /= primes[i];
			if(n==1){
				ans *= mid % M;
				break;
			}
		}
		else{
			ans *= mid % M;
			//cout << i << ' ' << primes[i] << ' ' << mid << ' ' << ans << "\n";
			i++;
			mid = 1;
		}
	}
	
	return ans;
}
void task()
{
    //code here...
    
    sieve(1000000);
    
    int a, b, c, ans = 0;
    
    cin >> a >> b >> c;
    
    for(int K=1; K<=a; K++){
		for(int L=1; L<=b; L++){
			for(int N=1; N<=c; N++){
				ans += divisors(K*L*N) % M;
			}
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

