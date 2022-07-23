//. . .Bismillahir Rahmanir Rahim. . .
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x)        cerr << #x << " == " << (x) << '\n';

const int MX = 3e5;
const ll MXL = 2e18+9;
ll dp[MX+5][3], a[MX+5], b[MX+5];
int n;
ll calc(int at, int l)
{
//    debug(at) debug(l) debug(a[at-1]) debug(a[at]) debug(b[at])
    if(at == n-1){
        if(a[at-1]+l == a[at]) return b[at];
        return 0;
    }

    if(dp[at][l] != -1LL) return dp[at][l];

    ll ans = MXL;

    if(a[at-1]+l != a[at]) ans = min(ans, calc(at+1, 0));
    if(a[at-1]+l != a[at]+1) ans = min(ans, calc(at+1, 1)+b[at]);
    if(a[at-1]+l != a[at]+2) ans = min(ans, calc(at+1, 2)+2LL*b[at]);

//    debug(at)
//    debug(l)
//    debug(ans)
    return dp[at][l] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;
    while(t--){
        cin >> n;

        for(int K = 0; K < n; K++) cin >> a[K] >> b[K];

        if(n == 1){
            cout << 0 << "\n";
            continue;
        }
        else if(n == 2){
            if(a[0] == a[1]) cout << min(b[0], b[1]) << "\n";
            else cout << 0 << "\n";
            continue;
        }

        for(int K = 0; K <= n; K++) dp[K][0] = dp[K][1] = dp[K][2] = -1LL;
        ll ans = calc(1, 0);
        ans = min(ans, calc(1, 1)+b[0]);
        ans = min(ans, calc(1, 2)+2LL*b[0]);

        cout << ans << "\n";
    }

    return 0;
}























