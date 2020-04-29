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
    ll t, a, b, c, d, x, y, x1, x2, y2, y1;

    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;

        if(x1-x2==0 && (a>0 || b>0)) cout << "No\n";
        else if(y1-y2==0 && (c>0 || d>0)) cout << "No\n";
        else if(a-b>x-x1 || b-a>x2-x) cout << "No\n";
        else if(c-d>y-y1 || d-c>y2-y) cout << "No\n";
        else if(abs(x1-x2)>=abs(a-b) && abs(y1-y2)>=abs(c-d)) cout << "Yes\n";
        else cout << "No\n";
    }
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
