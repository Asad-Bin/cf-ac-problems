//. . .Bismillahir Rahmanir Rahim. . .
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x)        cerr << #x << " == " << (x) << '\n';

const int MX = 2e6;
const ll mod = 1e9+7;
ll dp[MX+5];

int main()
{
    ll t, n;
    dp[0] = dp[1] = dp[2] = 0;
    dp[3] = dp[4] = 4;

    ll i = 8;
    for(int K = 5; K <= MX; K++){
        dp[K] = dp[K-1] + 2LL*dp[K-2] + (K%3==0 ? 4 : 0);
        dp[K] %= mod;
    }

    cin >> t;
    while(t--){
        cin >> n;

        //debug(dp[n]);
        cout << dp[n] << "\n";
    }

    return 0;
}























