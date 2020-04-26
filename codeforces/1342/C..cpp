//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 26 04 2020

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
    ll a, b, q, l, r, x, t;

    cin >> t;
    while(t--){
        cin >> a >> b >> q;
        if(a>b) swap(a,b);
        vector<ll> ara(a*b+1);

        for(ll K=1; K<=a*b; K++){
            if(K%a!=(K%b)%a) ara[K] = ara[K-1]+1;
            else ara[K] = ara[K-1];
        }

        while(q--){
            cin >> l >> r;

            ll ans=0;

            if(a*b>r) cout << ara[r] - ara[l-1] << " ";
            else{
                ll mid1=(l-1)/(a*b), mid2=r/(a*b);
                l = (l-1)%(a*b);
                r = r%(a*b);

                cout << (ara[a*b]*mid2+ara[r]) - (ara[a*b]*mid1+ara[l]) << " ";
            }
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
