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

bool test(int n)
{
    int a = n%10;
    n /= 10;
    int b = n%10;
    n /= 10;
    int c = n%10;
    n /= 10;

    if(a==b || a==c || a==n || b==c || b==n || c==n) return 0;
    else return 1;
}

void task()
{
    int n;
    bool res;

    cin >> n;

    n++;
    while(1){
        if(test(n)){
            cout << n << endl;
            return;
        }
        n++;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
