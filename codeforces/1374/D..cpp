//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 28 06 2020

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

void task()
{
    //code here...

    ll n, x, t, p;

    cin >> t;
    while(t--){
        cin >> n >> x;
        vi ara(n);
        map<int, int> mid;
        for(int K=0; K<n; K++) cin >> ara[K];

        for(int K=0; K<n; K++){
            p = x-(ara[K]%x);
            if(p==x) continue;
            mid[p]++;
        }

        ll ans=0;
        mid.erase(0);
        for(auto K : mid){
            if(K.second>0){
                ans = max(ans, (ll)K.first);
                K.second--;
                p = K.first+K.second*x;
                if(p<x && mid[p]-1>0) cout << "hi\n", ans = max(ans, (ll)K.first+(K.second+1)*x);
                else ans = max(ans, (ll)p);
            }
        }

        if(ans==0) cout << 0 << "\n";
        else cout << ans+1 << "\n";
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
