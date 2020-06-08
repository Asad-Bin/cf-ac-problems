//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 08 06 2020

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

ll gcd(ll a, ll b)
{
    if(a%b==0) return b;
    return gcd(b, a%b);
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

    int n, m;

    cin >> n;
    vi a(n+1), b(n+1), pos_b(n+1), ara(n+1);

    for(int K=1; K<=n; K++){
        cin >> a[K];
    }
    for(int K=1; K<=n; K++){
        cin >> b[K];
        pos_b[b[K]] = K;
        //cout << b[K] << ' ' << K << ' ' << pos_b[b[K]] << "\n";
    }

    for(int K=1; K<=n; K++){
        m = pos_b[a[K]] - K;
        //cout << m << ' ' << ara[m] << "\n";
        if(m<0) m = n - abs(m);
        //cout << m << ' ' << ara[m] << "\n";
        ara[m]++;
        //cout << m << ' ' << ara[m] << "\n";
    }
    int ans = 0;
    for(int K=0; K<=n; K++) ans = max(ara[K], ans);

    cout << ans << "\n";
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