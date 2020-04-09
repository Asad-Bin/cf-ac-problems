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
    ll n, Anton=0, Danik=0;
    string str;

    cin >> n >> str;

    for(ll K=0; K<n; K++){
        if(str[K]=='A') Anton++;
        else Danik++;
    }

    if(Anton>Danik) cout << "Anton" << endl;
    else if(Anton==Danik) cout << "Friendship" << endl;
    else cout << "Danik" << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
