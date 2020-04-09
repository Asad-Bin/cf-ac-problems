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
    string s, t;

    cin >> s >> t;

    int len = s.length();
    if(len!=t.length()){
        cout << "NO" << endl;
        return;
    }

    for(int K=0; K<len; K++){
        if(s[K]!=t[len-K-1]){
            cout << "NO" << endl;
            return;
        }
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
