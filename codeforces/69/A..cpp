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
    int n, x, y, z;
    ll ans=0, a=0, b=0, c=0;
    //vector<int> ara(n, 0);

    cin>>n;
    for(int K=0; K<n; K++){
        cin>>x>>y>>z;
        a += x;
        b += y;
        c += z;
    }

    ans = a*a + b*b + c*c;

    if(ans==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
