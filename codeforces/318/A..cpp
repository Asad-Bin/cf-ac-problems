//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 09 04 2020

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

#define    ll   long long

void task()
{
    ll n, k, mid;

    cin >> n >> k;

    mid = (n+1)/2;

    if(k<=mid){
        cout << (2*k-1) << endl;
    }
    else{
        k = k-mid;
        cout << 2*k << endl;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
