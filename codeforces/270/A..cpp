//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 14 04 2020

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
    int t, a;
    double lol;

    cin >> t;

    while(t--){
        cin >> a;

        lol = 1.0*360/(180-a);

        if(ceil(lol)-floor(lol)<0.0001) cout << "YES" << "\n";
        else cout << "NO" << "\n";
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
