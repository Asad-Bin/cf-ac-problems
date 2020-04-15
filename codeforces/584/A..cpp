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
    int n, t;

    cin >> n >> t;

    if(t==10 && n==1) cout << "-1\n" << endl;
    else if(t==10 && n!=1){
        for(int K=1; K<n; K++) cout << '1';
        cout << '0' << "\n";
    }
    else{
        for(int K=1; K<=n; K++) cout << t;
        cout << "\n";
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

