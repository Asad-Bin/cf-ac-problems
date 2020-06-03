//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 02 06 2020

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

bool myfunc(pii x, pii y)
{
    if(x.first==y.first) return x.second < y.second;
    return x.first < y.first;
}

void task()
{
    //code here...
    int n, m, k, t, x, y, i=1;

    cin >> n >> m >> k >> t;
    vector<pii> v;

    int l = k;

    while(l--){
        cin >> x >> y;
        v.PB(MP(x, y));
    }

    sort(v.begin(), v.end(), myfunc);
    //cout << "\n";
    //for(int K=0; K<(int)v.size(); K++) cout << v[K].first << ' ' << v[K].second << "\n";
    //cout << "\n";

    while(t--){
        cin >> x >> y;

        bool f = 0;
        int K=0;
        for(; K<k; K++){
            if(x==v[K].first && y==v[K].second){
                f = 1;
                break;
            }
            else if(x<v[K].first){
                break;
            }
            else if(x==v[K].first && y<v[K].second){
                break;
            }
        }
        //K++;

        int p = (x-1)*m + y;
        if(!f) p -= K;

        //cout << p << ' ' << K << "\n";

        if(f) cout << "Waste\n";
        else if(p%3==1) cout << "Carrots\n";
        else if(p%3==2) cout << "Kiwis\n";
        else cout << "Grapes\n";
    }
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

