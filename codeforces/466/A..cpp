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
    int n, m, a, b, normal, vip;

    cin >> n >> m >> a >> b;

    if(m>=n){
        cout << min(n*a, b) << endl;
        return;
    }

    normal = n * a;

    if(n%m==0){
        m = n / m;
        vip = m * b;
    }
    else {
        vip = min((n%m)*a,b);
        m = n / m;
        vip += (int)m * b;
    }

    cout << min(normal, vip) << endl;
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
