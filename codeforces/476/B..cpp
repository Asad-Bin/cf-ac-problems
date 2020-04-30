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

double up(int a, int b)
{
    ll ans=1;
    if(a<=b){
        for(int K=a+b, L=1; K>=b+1, L<=a; K--, L++){
            ans *= K;
            ans /= L;
        }
    }
    else {
        for(int K=a+b, L=1; K>=a+1, L<=b; K--, L++){
            ans *= K;
            ans /= L;
        }
    }

    return 1.0*ans;
}

void task()
{
    char a[11], b[11];

    scanf(" %[^\n]", a);
    scanf(" %[^\n]", b);

    int len = strlen(a), q=0, m=0, p=0;
    double ans = 0.00;

    for(int K=0; K<len; K++){
        if(a[K]=='+') p++;
        else if(a[K]=='-') m++;
    }

    for(int K=0; K<len; K++){
        if(b[K]=='+') p--;
        else if(b[K]=='-') m--;
        else if(b[K]=='?') q++;
    }

    if(m<0 || p<0){
        printf("%.9lf\n", ans);
        return;
    }
    else if(m==0 && p==0){
        printf("%.9lf\n", 1.0+ans);
        return;
    }

    ans = up(p,m) / pow(2,q);

    printf("%.9lf\n", ans);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

