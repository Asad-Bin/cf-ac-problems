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
    int r=0, c=0, x;

    for(int K=1; K<=5; K++){
        for(int L=1; L<=5; L++){
            cin>>x;
            if(x==1){
                r = K;
                c = L;
            }
        }
    }

    x = (abs(3-c)+abs(3-r));
    cout<<x<<endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
