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

int gcd(int a, int b)
{
    if(a%b==0) return b;
    return gcd(b, a%b);
}

void task()
{
    int a, b, n, mid;

    cin >> a >> b >> n;

    while(1){
        if(a==0 || n==0) mid = max(a, n);
        else mid = gcd(a, n);

        if(mid>n){
            cout << "1" << endl;
            break;
        }
        n -= mid;

        if(b==0 || n==0) mid = max(b, n);
        else mid = gcd(b, n);
        if(mid>n){
            cout << "0" << endl;
            break;
        }
        n -= mid;
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

