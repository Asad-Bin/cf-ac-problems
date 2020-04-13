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
    int t, n, a, b;

    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        char str[n+1];

        int i=0;
        for(int K=0; K<a; K++){
            if(i==b) i = 0;
            str[K] = 97+i;
            i++;
        }

        for(int K=a; K<n; K++){
            str[K] = str[K-a];
        }
        str[n] = '\0';

        cout << str << endl;
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

