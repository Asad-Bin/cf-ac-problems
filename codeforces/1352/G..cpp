//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 10 05 2020

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
    int n, t;

    cin >> t;
    while(t--){
        cin >> n;

        if(n==2 || n==3){
            cout << "-1" << "\n";
            continue;
        }
        else if(n==4){
            cout <<  '3' << ' ' << '1' << ' ' << '4' << ' ' << '2' << "\n";
            continue;
        }

        if(n&1){
            for(int K=n; K>=1; K-=2){
                cout << K << ' ';
            }
            cout << '4' << ' ' << 2 << ' ';
            for(int K=6; K<n; K+=2){
                cout << K << ' ';
            }
        }
        else{
            for(int K=n-1; K>=1; K-=2){
                cout << K << ' ';
            }
            cout << '4' << ' ' << 2 << ' ';
            for(int K=6; K<=n; K+=2){
                cout << K << ' ';
            }
        }
        cout << "\n";
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

