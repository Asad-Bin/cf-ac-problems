//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 26 04 2020

#include <bits/stdc++.h>

using namespace std;

// typedefs...
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> pll;

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
    ll n;
    cin >> n;
    vector<ll> ara(n);

    for(ll K=0; K<n; K++) cin >> ara[K];

    for(ll K=0; K<n; K++){
        ll min_ans=2e9, max_ans=0;

        if(K==0) min_ans = ara[K+1]-ara[0];
        else if(K==n-1) min_ans = ara[n-1]-ara[K-1];
        else min_ans = min((ara[K]-ara[K-1]), (ara[K+1]-ara[K]));
        max_ans = max((ara[K]-ara[0]), (ara[n-1]-ara[K]));

        cout << min_ans << ' ' << max_ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}

