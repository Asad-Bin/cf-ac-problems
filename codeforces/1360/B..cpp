//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 24 05 2020

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

    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> ara(n);

        for(int K=0; K<n; K++) cin >> ara[K];

        sort(ara.begin(), ara.end());

        int ans = 2000;
        for(int K=1; K<n; K++){
            ans = min(ans, ara[K]-ara[K-1]);
        }

        cout << ans << "\n";
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

