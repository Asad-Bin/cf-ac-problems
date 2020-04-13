//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 13 04 2020

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;

#define    ll   long long

void task()
{
    int n, lo, hi, record=0;

    cin >> n;
    vector<int> ara(n);

    for(int K=0; K<n; K++) cin >> ara[K];

    lo = hi = ara[0];
    for(int K=1; K<n; K++){
        if(ara[K]>hi){
            hi = ara[K];
            record++;
        }
        else if(ara[K]<lo){
            lo = ara[K];
            record++;
        }
    }

    cout << record << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
