
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
    ll n, x, count=1, pre;

    cin >> n;

    cin >> pre;
    for(ll K=1; K<n; K++){
        cin >> x;

        if(pre!=x) count++;
        pre = x;
    }

    cout << count << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
