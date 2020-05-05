//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 05 05 2020

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
    int n, x, ans=0, now=-1;

    cin >> n;

    for(int K=0; K<n; K++){
        cin >> x;
        //cout << x << ' ' << now << ' ' << ans << "\n";
        if(x==0){
            ans++;
            now = -1;
            continue;
        }

        if(x!=0 && now==-1){
            if(x!=3) now = x;
            continue;
        }

        if(x!=0 && now==x){
            ans++;
            now = -1;
            continue;
        }
        if(x!=0 && x==3){
            if(now==1) now=2;
            else now = 1;
            continue;
        }
        now = x;
    }

    cout << ans << "\n";
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

