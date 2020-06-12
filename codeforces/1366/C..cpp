//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 12 06 2020

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
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)

ll gcd(ll a, ll b)
{
    if(a%b==0) return b;
    return gcd(b, a%b);
}
ll lcm(ll a, ll b)
{
    return (a*b/gcd(a, b));
}
ll comb(ll a, ll b)
{
    ll x = max(a-b, b), ans=1;

    for(ll K=a, L=1; K>=x+1; K--, L++){
        ans *= K;
        ans /= L;
    }

    return ans;
}

int t, n, m;
int ara[30][30];

int func(int i, bool f)
{
    int cnt=0;
    for(int K=0; K<n; K++){
        for(int L=0; L<m; L++){
            if(K+L==i && ara[K][L]==f) cnt++;
        }
    }
    return cnt;
}

void task()
{
    //code here...

    cin >> t;
    while(t--){
        cin >> n >> m;

        for(int K=0; K<n; K++){
            for(int L=0; L<m; L++){
                cin >> ara[K][L];
            }
        }

        int ans = 0, cnt0, cnt1;
        for(int K=0; K<(int)(n+m-1)/2; K++){ // indicates cell level as level = cell+column for each cell in same level;
            cnt0 = func(K, 0)+func(n+m-1-K-1, 0); // finds out total number of zeroes in a level.
            cnt1 = func(K, 1)+func(n+m-2-K, 1); // finds out total number of ones in a level;
            ans += min(cnt0, cnt1); // as it is needed to flip all zeros or all ones and i want minimum.
            //cout << "test = " << cnt0 << ' ' << cnt1 << ' ' << ans << "\n";
        }

        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
