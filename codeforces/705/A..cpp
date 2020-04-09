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
    ll n;

    string str1 = "I hate it", str2 = "I love it", str3="I hate that ", str4="I love that ";

    cin >> n;

    if(n==1){
        cout << str1 << endl;
        return;
    }

    bool p = 0;
    for(ll K=1; K<n; K++){
        if(p==0){
            cout << str3;
            p = 1;
        }
        else if(p==1){
            cout << str4;
            p = 0;
        }
    }

    if(p==0) cout << str1 << endl;
    else cout << str2 << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
