//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 12 05 2020

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
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b))
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)

ll f(ll n)
{
    ll ans=0;
    for(ll K=2; K*K<=n; K++){
        if(n%K==0){
            ans = K;
            break;
        }
    }
    if(ans==0) ans = n;
    return ans;
}

void task()
{
    //code here...
    ll t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;

        ll mid = f(n);
        n = n + mid + (k-1)*2;

        cout << n << "\n";
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

