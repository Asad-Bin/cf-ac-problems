//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 30 04 2020

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
    ll n, c25=0, c50=0, x, mid;

    cin >> n;
    bool flag = 0;

    for(ll K=0; K<n; K++){
        cin >> x;

        if(x==25) c25++;
        else if(x==50)
        {
            if(c25>0){
                c25--;
                c50++;
            }
            else flag = 1;
        }
        else if(x==100)
        {
            if(c50>0 && c25>0){
                c25--;
                c50--;
            }
            else if(c25>=3){
                c25-=3;
            }
            else flag = 1;
        }
    }

    if(flag == 0) cout << "YES\n";
    else cout << "NO\n";
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
