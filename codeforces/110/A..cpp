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
    int count=0, mid;
    string str;
    cin >> str;

    int len = str.length();

    for(int K=0; K<len; K++){
         if(str[K]=='4' || str[K]=='7'){
            count++;
         }
    }
    //cout<<count<<endl;

    while(1){
        mid = count%10;
        count /= 10;

        if(mid!=4 && mid!=7){
            cout << "NO" << endl;
            return;
        }

        if(count==0) break;
    }

    cout << "YES" << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
