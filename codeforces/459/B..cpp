//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 19 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define    pi    acos(-1.0)

void task()
{
    ll n;

    cin >> n;
    vector<ll> ara(n);

    for(ll K=0; K<n; K++) cin >> ara[K];

    sort(ara.begin(), ara.end());

    ll dif = ara[n-1] - ara[0];

    ll a = count(ara.begin(), ara.end(), ara[0]);
    ll b = count(ara.begin(), ara.end(), ara[n-1]);

    ll ans;
    if(ara[0]==ara[n-1]) ans = a*(a-1)/2;
    else ans = (a+b)*(a+b-1)/2 - a*(a-1)/2 - b*(b-1)/2;

    cout << dif << ' ' << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
