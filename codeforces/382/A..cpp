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

    string a, b, c;
    int n, m;

    cin >> a >> c;

    n = a.length();
    m = c.length();
    if((n+m-1)%2!=0){
        cout << "Impossible\n";
        return;
    }
    for(int K=0; K<n; K++){
        if(a[K]=='|'){
            b = a.substr(K+1, n-1);
            a.erase(K, n-K);
        }
    }

    int p = (n+m-1)/2;
    string s = c.substr(0, p-a.length());
    c.erase(0, s.length());
    a += s;
    b += c;

    if(a.length()!=b.length()){
        cout << "Impossible\n";
        return;
    }

    cout << a << '|' << b << "\n";
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

