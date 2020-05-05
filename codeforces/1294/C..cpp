//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 06 05 2020

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
    ll t, n, a, b, c;

    cin >> t;
    while(t--){
        cin >> n;

        a = b = c = -1;
        for(ll K=2; K*K<=n; K++){
            if(n%K==0){
                a = K;
                n /= K;
                break;
            }
        }

        for(ll K=2; K*K<=n; K++){
            if(K!=a && n%K==0){
                b = K;
                n /= K;
                break;
            }
        }

        c = n;
        //cout << a << ' ' << b << ' ' << c << "\n";

        if(a!=-1 && b!=-1 && c!=-1 && a!=c && b!=c && c!=1) cout << "YES\n" << a << ' ' << b << ' ' << c << "\n";
        else cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

