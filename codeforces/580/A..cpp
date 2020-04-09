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
    ll n, max_ = 1;
    cin >> n;
    vector<ll> ara(n);
    for(int K=0; K<n; K++){
        cin >> ara[K];
    }

    long int low = 0;
    for(int K=1; K<n-1; K++){
        if(ara[K]<ara[K-1]) low = K;
        if(ara[K]>ara[K+1]){
            //hi = K;
            if(max_<(K-low+1)) max_ = (K-low+1);
        }
        else if(K==n-2 && ara[K]<=ara[K+1]){
            //hi = K;
            if(max_<(K-low+2)) max_ = (K-low+2);
        }
    }
    if(n==2) max_++;

    cout << max_ << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
