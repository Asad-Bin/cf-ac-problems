//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 20 05 2020

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


ll gcd(ll a, ll b)
{
    if(a%b==0) return b;
    return gcd(b, a%b);
}

void task()
{
    //code here...
    ll l, r, a, b, c=-1;

    cin >> l >> r;

    for(ll K=l; K<r; K++){
        for(ll L=r; L>K; L--){
            if(gcd(L, K)>1){
                a = K;
                c = L;
                break;
            }
        }
        if(c!=-1) break;
    }

    if(c<=a || c==-1){
        cout << "-1\n";
        return;
    }
    else {
        for(ll K=a+1; K<c; K++){
            if(gcd(a, K)==1 && gcd(c, K)==1){
                cout << a << ' ' << K << ' ' << c << "\n";
                return;
            }
        }
    }

    cout << "-1\n";
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

