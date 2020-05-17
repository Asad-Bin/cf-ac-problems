//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 17 05 2020

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

ll add(ll a)
{
    ll ans = 0, hi=10, mid;
    while(1){
        mid = a%10;
        a = a/10;
        ans = max(ans, mid);
        hi = min(hi, mid);
        if(a==0) break;
    }

    return ans*hi;
}

void task()
{
    //code here...
    ull t, a, k;

    cin >> t;
    while(t--){
        cin >> a >> k;
        ull ans = a, p;

        for(ull K=2; K<=k; K++){
            p = add(ans);
            if(p==0) break;
            ans = ans + p;
        }

        cout << ans << "\n";
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

