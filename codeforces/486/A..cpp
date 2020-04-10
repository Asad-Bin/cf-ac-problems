//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 10 04 2020

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
    ll n;
    cin >> n;

    if(n%2==0){
        cout << n/2 << endl;
    }
    else{
        cout << ((n-1)/2)-n << endl;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

