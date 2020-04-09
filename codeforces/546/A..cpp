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
    ll k, n, w, total=0;

    cin>>k>>n>>w;

    for(int K=1; K<=w; K++){
        total += K*k;
    }

    total -= n;
    if(total>0) cout<<total<<endl;
    else cout<<'0'<<endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
