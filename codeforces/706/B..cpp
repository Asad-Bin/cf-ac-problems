//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 15 04 2020

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;

#define    ll   long long
#define    pi   acos(-1.0)

void task()
{
    long int n, q, x;
    vector<long int> hishab(100001);

    cin >> n;
    for(int K=0; K<n; K++){
        cin >> x;
        hishab[x]++;
    }

    for(long int K=2; K<=100000; K++) hishab[K] += hishab[K-1];

    cin >> q;
    for(long int K=0; K<q; K++){
        cin >> x;

        if(x>=100000) cout << hishab[100000] << "\n";
        else cout << hishab[x] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}

