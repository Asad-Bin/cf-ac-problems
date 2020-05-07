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
    ll t, n, mod;

    cin >> t;
    while(t--){
        cin >> n;
        vector<ll> ara(n);
        vector<bool> mark(n+1);
        bool flag = 0;

        for(ll K=0; K<n; K++) cin >> ara[K];

        for(int K=0; K<n; K++){
            mod = K+ara[K];
            mod = mod%n;
            if(mod<0) mod = (mod+n);

            if(!mark[mod]) mark[mod] = 1;
            else{
                cout << "NO\n";
                flag = 1;
                break;
            }
        }

        if(flag == 0) cout << "YES\n";
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

