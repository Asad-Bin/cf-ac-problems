//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 17 05 2020

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

    char s[200001];
    ll t;
    cin >> t;
    while(t--){
        scanf("%s", s);

        ll n = strlen(s), ans=200001;
        set<char> ss;
        char save;
        ss.insert(s[0]);

        for(ll K=1; K<n; K++){
            ss.insert(s[K]);

            if(ss.size()==3){
                //cout << K << " ";
                for(ll L=K-2; L>=0; L--){
                    if(s[L]!=s[K-1] && s[L]!=s[K]){
                        //cout << s[L] << ' ' << s[K-1] <<  ' ' << ans << ' ' << K-L+1 << "\n";
                        ans = min(ans, K-L+1);
                        ss.erase(s[L]);
                        break;
                    }
                }
            }
        }
        if(ans==200001) ans = 0;

        cout << ans << "\n";
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

