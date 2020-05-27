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

    int r1, r2, c1, c2, d1, d2, a, b, c, d;

    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;

    a = (r1+c1-d2)/2;
    d = (r2+c2-d2)/2;
    b = r1 - a;
    c = r2 - d;

    if(a*2!=(r1+c1-d2) || d*2!=(r2+c2-d2) || a<1 || a>9 || b<1 || b>9 || c<1 || c>9 || d<1 ||d>9 || a==b || b==c || a==c || a==d || b==d || c==d){
        cout << "-1\n";
        return;
    }

    cout << a << ' ' << b << "\n" << c << ' ' << d << "\n";
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

