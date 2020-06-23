//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 22 06 2020

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

int gcd (int a, int b) {
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

void bruce(int n)
{
    cout << "\nExpected answer:\n";
    cout << "\nAnswer recieved:\n";
}

const int MX = 2e5;
int ara[MX+1], lol[MX+1], t, n, k;;
ll f1()
{
    return 0;
    ll i = 0, ans=0;
    for(int K=0; K<k; K++){
        ans += (ll)(ara[i]+ara[i+lol[K]-1]);
        i += lol[K];
    }

    return ans;
}

ll f2()
{
    ll ans=0, i=0;

    for(int K=0; K<k; K++){
        if(lol[K]==1) ans += (ll)2*ara[K];
        else ans += (ll)ara[K];
        lol[K]--;
        i++;
    }

    for(int K=0; K<k; K++){
        //cout << K << ' ' << i << ' ' << ara[i+lol[K]-1] << "\n";
        if(lol[K]>0) ans += (ll)(ara[i+lol[K]-1]);
        i += lol[K];
    }

    /*while(1)
    {
        bool f = 0;
        for(int K=0; K<k; K++){
            if(lol[K]==1){
                ans += ara[i];
            }
            lol[K]--;
            if(lol[K]>0){
                i++;
                f = 1;
            }
        }
        //cout << "hi\n";

        if(f==0) break;
    }*/

    return ans;
}

bool myfunc(int a, int b)
{
    return a>b;
}

void task()
{
    //code here...

    cin >> t;
    while(t--){
        cin >> n >> k;

        for(int K=0; K<n; K++) cin >> ara[K];
        for(int K=0; K<k; K++) cin >> lol[K];

        sort(ara, ara+n, myfunc);
        sort(lol, lol+k);

        cout << f2() << "\n";
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

