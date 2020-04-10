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
    int n;

    cin >> n;
    vector<int> ara(n);

    for(int K=0; K<n; K++){
        cin >> ara[K];
    }

    sort(ara.begin(), ara.end());

    for(int K=0; K<n; K++) cout << ara[K] << ' ';
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

