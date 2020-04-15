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
    ll t, a, c, b, d, x, y;

    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;

        if(b==c)cout << b << ' ' << c << ' ' << c << endl;
        else if(b!=1) cout << b << ' ' << c-1 << ' ' << c << endl;
        else cout << b << ' ' << c << ' ' << c << endl;
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

