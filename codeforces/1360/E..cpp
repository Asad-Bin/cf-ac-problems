//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 24 05 2020

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
    int t, n;

    cin >> t;

    while(t--){
        cin >> n;
        char s[n][n+1];
        bool flag = 0;

        for(int K=0; K<n; K++) scanf("%s", s[K]);

        for(int K=0; K<n-1; K++){
            for(int L=0; L<n-1; L++){
                if(s[K][L]=='1' && (s[K+1][L]!='1' && s[K][L+1]!='1')){
                    cout << "NO\n";
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
        }

        if(flag==0) cout << "YES\n";
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

