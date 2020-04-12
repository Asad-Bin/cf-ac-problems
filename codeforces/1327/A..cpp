//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 12 04 2020

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
    ll t, n, k, mid;

    cin >> t;

    while(t--){
        cin >> n >> k;

        if(n>=k*k){
            mid = n-k*k;

            if(n==0 || mid%2==0)cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else cout << "NO" << endl;
    }
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

