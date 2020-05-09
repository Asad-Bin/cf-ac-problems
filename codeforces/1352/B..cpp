//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 09 05 2020

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

    ll t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;

        bool flag = 0;
        if((n-k+1)%2==1){
            cout << "YES\n";
            for(ll K=1; K<k; K++) cout << '1' << ' ';
            cout << (n-k+1) << "\n";
        }
        else{
            flag = 1;
        }

        if(flag==1){
            if((n-k*2+2)>0 && (n-k*2)%2==0){
                cout << "YES\n";
                for(ll K=1; K<k; K++) cout << '2' << ' ';
                cout << (n-k*2+2) << "\n";
            }
            else cout << "NO\n";
        }
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

