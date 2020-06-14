//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 14 06 2020

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

    int n, save=-1;

    cin >> n;
    vi ara(n), lol, ans(n, -1);
    vector<bool> mark(n+1);

    for(int K=0; K<n; K++){
        cin >> ara[K];
        mark[ara[K]] = 1;
    }
    for(int K=1; K<n; K++){
        if(ara[K]!=ara[K-1]) ans[K] = ara[K-1];
     //cout << ans[K] << "\n";
    }
    int K, L, i;
    K = L = i = 0;
    while(K<n && L<n){
        if(mark[i]){
            i++;
            continue;
        }
        if(ara[K]==i){
            i++;
            K++;continue;
        }
        if(ans[L]!=-1){
            L++; continue;
        }

        ans[L] = i;
        i++;
        //cout << ara[K] << ' ' << ans[L] << ' ' << i << "\n";
    }

    for(int K=0; K<n; K++){
        if(ans[K]==-1){
            cout << "-1\n";
            return;
        }
    }

    for(int K=0; K<n; K++) cout << ans[K] << ' ';
    cout << "\n";
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

