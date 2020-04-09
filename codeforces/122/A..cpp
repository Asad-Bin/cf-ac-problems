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

bool test(int x)
{
    int mid;
    while(1){
        mid = x%10;
        if(mid!=4 && mid!=7)return 0;
        x /= 10;
        if(x==0) break;
    }
    return 1;
}

void task()
{
    int n, mid;
    bool res;
    cin>>n;

    for(int K=1; K<1000; K++){
        mid = n / K;
        if(mid==0) break;

        if(n%K==0){
            res = test(n/K);
            if(res==1){
                cout<<"YES"<<endl;
                return;
            }
        }
    }

    cout<<"NO"<<endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
