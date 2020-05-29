//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 29 05 2020

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
    int n;
    string s = "ROYGBIV";

    cin >> n;
    int p = n/7;

    for(int K=0; K<p; K++){
        cout << s;
    }

    if(n-7*p==1) cout << "G" << "\n";
    else if(n-7*p==2) cout << "GB\n";
    else if(n-7*p==3) cout << "YGB\n";
    else if(n-7*p==4) cout << "YGBI\n";
    else if(n-7*p==5) cout << "OYGBI\n";
    else if(n-7*p==6) cout << "OYGBIV\n";
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

