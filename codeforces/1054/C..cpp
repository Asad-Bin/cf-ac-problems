//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 04 06 2020

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

    int n, m=0;

    cin >> n;
    vi l(n), r(n), ara(n);

    for(int K=0; K<n; K++) cin >> l[K];
    for(int K=0; K<n; K++) cin >> r[K];

    if(l[0]!=0 || r[n-1]!=0){
        cout << "NO\n";
        return;
    }

    int first = n - r[0], fn = r[0], last = n - l[n-1], ln=l[n-1];
    for(int K=0; K<n; K++){
        ara[K] = n - l[K] - r[K];
        //if(ara[K]>first) fn--;
        //if(ara[K]>last) ln--;
        //if(ara[K]<=0){
        //    cout << "NO\n";
        //    return;
        //}
        //cout << ara[K] << ' ';
    }
    //cout << "\n";
    //return;

    int cnt=0;
    for(int K=0; K<n; K++){
        cnt=0;
        for(int L = K-1; L>=0; L--){
            if(ara[L]>ara[K]) cnt++;
        }
        if(cnt!=l[K]){
            cout << "NO\n";
            return;
        }
    }

    for(int K=0; K<n; K++){
        cnt=0;
        for(int L = K+1; L<n; L++){
            if(ara[L]>ara[K]) cnt++;
        }
        if(cnt!=r[K]){
            cout << "NO\n";
            return;
        }
    }


    //if(ln!=0 || fn!=0) {
    //    cout << "NO\n";
    //    return;
    //}
    //if(ara[0]==ara[n-1]){
    //    cout << "NO\n";
    //    return;
    //}

    cout << "YES\n";
    for(int K=0; K<n; K++) cout << ara[K] << ' ';
    cout << "\n";
    return;

    /*for(int K=0; K<n; K++){
        ara[K] = m - (l[K]+r[K]);
    }

    cout << "YES\n";
    for(int K=0; K<n; K++) cout << ara[K] << ' ';
    cout << "\n";*/
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
