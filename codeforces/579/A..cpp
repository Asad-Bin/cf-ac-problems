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
    ll x, count=0;

    cin >> x;

    while(x){
        if(x&1) count++;

        x >>= 1;
    }

    cout << count << endl;
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
