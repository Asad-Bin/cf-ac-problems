//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 08 04 2020

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

#define   ll   long long

void task()
{
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        bool flag =0;
        ll x=n+1, y=n+1;

        vector<ll> ara(n);
        vector<ll> res(n);

        for(ll K=0; K<n; K++){
            cin>>ara[K];
            if(ara[K]==1) x = min(x, K);
            else if(ara[K]==-1) y = min(y, K);
        }
        for(ll K=0; K<n; K++){
            cin>>res[K];
        }

        for(ll K=n-1; K>=0; K--){
            if(res[K]>ara[K] && x>=K) flag=1;
            else if(res[K]<ara[K] && y>=K) flag=1;
        }

        if(flag==1){
            cout<<"NO"<<endl;
            continue;
        }
        //if(res[0]>ara[0] || res[0]<ara[0]){
        //    cout<<"NO"<<endl;
        //    continue;
        //}
        cout<<"YES"<<endl;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
