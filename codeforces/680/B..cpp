//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 28 05 2020

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


void task()
{
    //code here...
    int n, a, ans=0;
    bool p;

    cin >> n >> a;
    vector<bool> ara(n+1);

    for(int K=1; K<=n; K++) cin >> p, ara[K]=p;

    int x = min(a-1, n-a);
    //cout << x << "\n";
    for(int K=0; K<=x; K++){
        if(K==0 && ara[a]==1) ans++;
        else if(ara[a-K]==1 && ara[a+K]==1) ans+=2;
    }
    for(int K=a-x-1; K>=1; K--){
        if(ara[K]==1) ans++;
    }
    for(int K=a+x+1; K<=n; K++){
        if(ara[K]==1) ans++;
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

