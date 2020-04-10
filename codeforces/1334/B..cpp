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
    ll t, n, x;

    cin >> t;
    while(t--){
        cin >> n >> x;

        vector<ll> ara(n);

        for(ll K=0; K<n; K++){
            cin >> ara[K];
        }

        sort(ara.begin(), ara.end());
        ll count_=0, rem=0;
        bool flag = 0;

        for(long int K=n-1; K>=0; K--){
            if(ara[K]>x) rem+=(ara[K]-x);
            else if(ara[K]<x) rem-=(x-ara[K]);

            if(rem<0){
                cout << count_ << endl;
                flag = 1;
                break;
            }
            else if(rem==0 && ara[K]!=x){
                count_++;
                cout << count_ << endl;
                flag = 1;
                break;
            }
            count_++;
        }

        if(flag==0) cout << count_ << endl;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
