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
    vector<bool> ara(26);

    cin>>str;

    int len = str.length(), count=0, mid;
    for(int K=0; K<len; K++){
        mid = str[K] - 97;
        if(ara[mid]==0){
            count++;
            ara[mid] = 1;
        }
    }

    if(count%2==0) cout<<"CHAT WITH HER!"<<endl;
    else cout<<"IGNORE HIM!"<<endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
