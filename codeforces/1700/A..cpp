//. . .Bismillahir Rahmanir Rahim. . .
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define debug(x)        cerr << #x << " == " << (x) << '\n';

int main()
{
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;

        ll ans = 0;
        for(int K = 1; K <= m; K++) ans += K;
        for(int K = 2; K <= n; K++) ans += K*m;

        cout << ans << "\n";
    }

    return 0;
}























