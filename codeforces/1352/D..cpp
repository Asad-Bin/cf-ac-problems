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

    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> ara(n);

        for(int K=0; K<n; K++) cin >> ara[K];

        int a = ara[0], b=0, moves = 1, al=ara[0], bb=0, lo=1, hi=n-1;
        if(n==1){
            cout << '1' << ' ' << ara[0] << ' ' << '0' << "\n";
            continue;
        }
        while(1){
            bb = 0;
            for(int K=hi; K>=lo; K--){
                bb += ara[K];
                b += ara[K];
                //moves++;
                hi--;
                if(bb>al) break;
                if(lo>hi) break;
            }
            moves++;
            //cout << moves << ' ' << a << ' ' << b << ' ' << bb << "\n";
            if(hi<lo) break;

            al = 0;
            for(int K=lo; K<=hi; K++){
                al += ara[K];
                a += ara[K];
                //moves++;
                lo++;
                if(al>bb) break;
                if(lo>hi) break;
            }
            moves++;
            //cout << moves << ' ' << a << ' ' << b << ' ' << bb << "\n\n";
            if(hi<lo) break;
        }

        cout << moves << ' ' << a << ' ' << b << "\n";
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

