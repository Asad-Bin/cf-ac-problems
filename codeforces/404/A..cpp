//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 20 05 2020

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
    cin >> n;
    string s[n];

    for(int K=0; K<n; K++) cin >> s[K];

    char d = s[0][0], c = s[0][1];

    if(c==d){cout << "NO\n"; return;}

    for(int K=0; K<n; K++){
        if(s[K][K]!=d){cout << "NO\n"; return;}
        else if(s[K][n-K-1]!=d) {cout << "NO\n"; return;}
    }

    for(int K=0; K<n; K++){
        for(int L=0; L<n; L++){
            if(K!=L && L!=n-K-1){
                if(s[K][L]!=c) {cout << "NO\n"; return;}
            }
        }
    }

    cout << "YES\n";
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

