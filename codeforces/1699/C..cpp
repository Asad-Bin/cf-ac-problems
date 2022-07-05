//. . .Bismillahir Rahmanir Rahim. . .
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x)        cerr << #x << " == " << (x) << '\n';

const int MX = 1e5;
const ll mod = 1e9+7;

int ara[MX+5], pos[MX+5];

int main()
{
    //freopen("in.txt", "r", stdin);

    int t, n;
//    ll fact[MX+5];
//    fact[0] = fact[1] = 1;
//    for(int K = 2; K <= MX; K++) fact[K] = fact[K-1]*K%mod;

    cin >> t;
    while(t--){
        cin >> n;

        for(int K = 0; K < n; K++){
            cin >> ara[K];
            pos[ara[K]] = K;
        }

        int l = pos[0], r = pos[0];
        ll ans = 1;

        for(int K = 1; K < n; K++){
            if(pos[K] >= l && pos[K] <= r){
                ll mid = (r-l+1);
                ans = ans*(mid-K)%mod;
            }
            else{
                l = min(l, pos[K]);
                r = max(r, pos[K]);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}























