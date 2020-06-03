//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 03 06 2020

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

    int n;
    cin >> n;
    vector<int> ara(n+1), x(n+1), ans;

    for(int K=1; K<=n; K++){
        cin >> ara[K];
    }

    for(int K=1; K<=n; K++){
        x[K-1] = ara[K] - ara[K-1];
        for(int L=1; L<=n; L++){
            if(ara[L]-ara[L-1] != x[(L-1)%K]) break;
            if(L==n) ans.PB(K);
        }
    }

    cout << ans.size() << "\n";
    for(int K=0; K<ans.size(); K++) cout << ans[K] << ' ';
    cout << "\n";
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
