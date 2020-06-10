//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 10 06 2020

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

    ull n, ans=0, m=0, save;

    cin >> n;
    vector<ull> ara(n);
    for(int K=0; K<n; K++){
        cin >> ara[K];

        //m = max(m, ara[K]);
    }

    ull ss=0, a, x;
    for(int K=0; K<n; K++){
        //a = ara[K];
        //ss = max(ss, a);
        for(int L=0; L<n; L++){
            //ss = a|ara[L];
            //ss = max(ss, x);
            for(int M=0; M<n; M++){
                x = (ara[K]|ara[L])|ara[M];
                ss = max(ss, x);
            }
        }
    }

    cout << ss << "\n";
    return;

    ull i = 1;
    //cout << __builtin_popcount(ss) << "\n";
    while(ss){
        if(ss&1){
            ans += i;
            //i<<=1;
            //cout << __builtin_popcount(ss) << ' ' << ans << "\n";
        }

        i<<=1;
        ss>>=1;
    }

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
