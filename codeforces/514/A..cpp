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
    ll x, calc=1, n=0, mid;

    cin >> x;
    while(1){
        mid = x % 10;
        x /= 10;
        //mid = min(mid, (9-mid));
        if(mid==9 && x!=0) mid = 0;
        else if((9-mid)<mid && mid!=9) mid = (9-mid);

        n += (calc*mid);
        if(x==0) break;
        calc *= 10;
    }

    cout << n << "\n";
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

