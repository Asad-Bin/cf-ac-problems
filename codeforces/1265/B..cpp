//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 15 06 2020

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

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
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


void task()
{
    //code here...

    int t, n, p, x;

    cin >> t;
    while(t--){
        cin >> n;
        vi ara(n), pos(n+1);
        vector<bool> mark(n);
        p = 1e9;
        char s[n+2];
        for(int K=0; K<n; K++) cin >> ara[K];
        for(int K=0; K<n; K++){
            x = ara[K];
            pos[x] = K;
            //p = min(p, ara[K]);
        }

        for(int K=0; K<=n; K++) s[K] = '0';
        s[n+2] = '\0';

        //x = pos[p];
        //mark[x] = 1;
        //s[p] = '1';
        //int u = p;
        s[1] = '1';
        int pos_max = pos[1], pos_min = pos[1];

        for(int K=1; K<=n; K++){
            pos_max = max(pos_max, pos[K]);
            pos_min = min(pos_min, pos[K]);
            if(pos_max-pos_min+1==K) s[K] = '1';

            /*if(K==p) continue;
            x = pos[K];
            if(x==0 && mark[1] && K==u+1) s[K] = '1', u = K;
            else if(x==n-1 && mark[x-1] && K==u+1) s[K] = '1', u = K;
            else if(x==0 && !mark[1]) s[K] = '0';
            else if(x==n-1 && !mark[x-1]) s[K] = '0';
            else if(mark[x-1] && mark[x+1] && s[ara[x-1]]=='1' && s[ara[x+1]]=='1') s[K] = '1';
            else if((mark[x-1] || mark[x+1]) && K==u+1) s[K] = '1', u = K;
            else s[K] = '0';

            mark[x] = 1;
            //u = K;
            //for(int K=1; K<=n; K++) cout << s[K];
        //cout << "\n";*/
        }
        //s[n+2] = '\0';

        for(int K=1; K<=n; K++) cout << s[K];
        cout << "\n";
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

