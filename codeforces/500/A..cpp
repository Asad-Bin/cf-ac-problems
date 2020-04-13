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
    long int n, t, next;

    cin >> n >> t;
    vector<long int> ara(n);

    for(long int K=1; K<=n-1; K++){
        cin >> ara[K];
    }

    for(long int K=1; K<=n-1; ){
        next = K+ara[K];

        if(next==t){
            cout << "YES" << endl;
            return;
        }
        K = next;
    }
    cout << "NO" << endl;
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

