//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 10 05 2020

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
    int n0, n1, n2, t;

    cin >> t;
    while(t--){
        cin >> n0 >> n1 >> n2;

        if(n1==0){
            if(n0==0){
                cout << string(n2+1, '1') << "\n";
            }
            else if(n2==0){
                cout << string(n0+1, '0') << "\n";
            }
            continue;
        }

        string ans="";

        for(int K=0; K<n1+1; K++){
            if(K&1) ans += "0";
            else ans += "1";
        }
        //cout << ans << ' ';
        ans.insert(1, string(n0, '0'));
        ans.insert(0, string(n2, '1'));

        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

