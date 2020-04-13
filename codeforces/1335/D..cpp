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
    ll t;

    cin >> t;
    while(t--){
        char str[9][10];
        int i=0;

        for(int K=0; K<9; K++) scanf(" %[^\n]", str[K]);

        for(int K=0; K<9; K+=3){
            if(str[K][i]!='1') str[K][i] = '1';
            else str[K][i] = '2';

            if(str[K+1][i+3]!='1') str[K+1][i+3] = '1';
            else str[K+1][i+3] = '2';

            if(str[K+2][i+6]!='1') str[K+2][i+6] = '1';
            else str[K+2][i+6] = '2';

            i++;
        }

        for(int K=0; K<9; K++) printf("%s\n", str[K]);
    }
}

int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}

