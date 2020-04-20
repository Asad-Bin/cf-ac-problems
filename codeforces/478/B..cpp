//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 20 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

ll perm(ll x)
{
    ll ans=1;

    for(int K=x; K>=x-2+1; K--) ans*=K;

    return ans/2;
}

void task()
{
    ll n, m, mn, mx, mod, avrg;

    cin >> n >> m;

    avrg = (int)n/m;
    mod = n%m;
    mx = perm(n-m+1);

    if(avrg>1 && avrg*m<n) mn = (m-mod)*perm(avrg) + mod*perm(avrg+1);
    else if(avrg>1 && avrg*m==n) mn = m*perm(avrg);
    else if(avrg==1 && avrg*m<n) mn = mod*perm(avrg+1);
    else mn = 0;

    cout << mn << ' ' << mx << "\n";
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

