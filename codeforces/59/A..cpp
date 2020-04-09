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
    string str;
    cin >> str;

    int len = str.length(), up=0, low=0;

    for(int K=0; K<len; K++){
        if(str[K]>='A' && str[K]<='Z') up++;
        else low++;
    }

    if(up>low){
        for(int K=0; K<len; K++){
            if(str[K]>='a' && str[K]<='z') str[K] = str[K] - 'a' + 'A';
        }
    }
    else{
        for(int K=0; K<len; K++){
            if(str[K]>='A' && str[K]<='Z') str[K] = str[K] - 'A' + 'a';
        }
    }

    cout << str << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
