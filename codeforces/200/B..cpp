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
    int n, x;
    ll sum=0;

    cin >> n;
    for(int K=0; K<n; K++){
        cin >> x;

        sum+=x;
    }

    double ans = 1.0 * sum / n;

    printf("%lf\n", ans);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

