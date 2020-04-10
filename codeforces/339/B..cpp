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
    ll n, m, time=0, count;

    cin >> n >> m;
    vector<int> ara(m);

    for(ll K=0; K<m; K++) cin >> ara[K];

    ll pre = 1;

    for(ll K=0; K<m; K++){

        if(ara[K]>=pre) time += (ara[K]-pre);
        else if(ara[K]<pre) time += (n+ara[K]-pre);

        pre = ara[K];
    }

    cout << time << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

