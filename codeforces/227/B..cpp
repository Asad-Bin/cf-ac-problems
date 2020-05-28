//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 28 05 2020

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
    int n, m, x;
    ll v=0, p=0;

    si(n);
    vector<int> ara(100001);
    for(int K=0; K<n; K++){
        si(x);
        ara[x] = K+1;
    }

    si(m);
    while(m--){
        si(x);
        if(ara[x]==0){
            v += n;
            p += n;
            continue;
        }
        //if(ara[x]<n-ara[x]) v+=;
        //else if(ara[x]>n-ara[x]) p++;
        v += (ll)ara[x];
        p += (ll)n-ara[x]+1;
    }

    cout << v << ' ' << p << "\n";
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

