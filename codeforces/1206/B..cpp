//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 01 05 2020

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
    ll x, ans=0, p=0, z=0, n=0;

    cin >> x;
    vector<ll> ara(x);

    for(ll K=0; K<x; K++) cin >> ara[K];

    for(ll K=0; K<x; K++){
        if(ara[K]==1){
            p++;
        }
        else if(ara[K]==-1){
            n++;
        }
        else if(ara[K]==0){
            z++;
        }
        else if(ara[K]<-1){
            n++;
            ans += (-1-ara[K]);
        }
        else{
            p++;
            ans += (ara[K]-1);
        }
    }

    if(n%2==1 && z>0) {
        z--;
        n++;
        ans++;
    }
    else if(n%2==1 && z==0){
        ans += 2;
    }

    ans += z;

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}

