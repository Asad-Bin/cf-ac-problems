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
    int n, t, len;
    string str;
    char c;

    cin >> n >> t;
    cin >> str;

    len = str.length();

    for(int K=1; K<=t; K++){
        for(int L=0; L<len-1; L++){
            if(str[L]=='B' && str[L+1]=='G'){
                c = str[L];
                str[L] = str[L+1];
                str[L+1] = c;
                L++;
            }
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
