//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 27 05 2020

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
    int n, total=0;

    cin >> n;
    vector<int> ara(n), ans(n);

    for(int K=0; K<n; K++) cin >> ara[K];

    for(int K=0; K<n; K++){
        ans[K] = ara[K] / 2;
        total += ans[K];
    }

    for(int K=0; K<n; K++){
        if(total==0) break;
        if(abs(ara[K])%2==1){
            if(total<0 && ara[K]>0){
                ans[K]++;
                total++;
            }
            else if(total>0 && ara[K]<0){
                ans[K]--;
                total--;
            }
        }
    }

    for(int K=0; K<n; K++) cout << ans[K] << "\n";
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

