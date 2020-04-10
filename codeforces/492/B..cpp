//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 10 04 2020

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

#define    ll   long long

void task()
{
    ll l, n;

    cin >> n >> l;
    vector<ll> ara(n);

    for(int K=0; K<n; K++){
        cin >> ara[K];
    }

    sort(ara.begin(), ara.end());

    ll dif = ara[0]*2;
    for(int K=1; K<n; K++){
        dif = max(dif, (ara[K]-ara[K-1]));
    }
    dif = max(dif, (l-ara[n-1])*2);

    double ans = 1.0 * dif / 2;

    printf("%lf\n", ans);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

