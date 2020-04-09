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
    int a, b, c, x, max_;

    cin >> a >> b >> c;

    max_ = a + b * c;
    x = a * (b + c);
    if(max_<x) max_ = x;
    x = a * (b * c);
    if(max_<x) max_ = x;
    x = (a + b) * c;
    if(max_<x) max_ = x;
    x = a * b + c;
    if(max_<x) max_ = x;
    x = a + b + c;
    if(max_<x) max_ = x;

    cout << max_ << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
