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
    int n, m;
    char c;
    bool flag = 0;

    cin >> n >> m;

    for(int K=1; K<=n; K++){
        for(int L=1; L<=m; L++){
            cin >> c;
            if(c=='C') flag = 1;
            else if(c=='M') flag = 1;
            else if(c=='Y') flag = 1;
        }
    }

    if(flag==1) cout << "#Color" << endl;
    else cout << "#Black&White" << endl;
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

