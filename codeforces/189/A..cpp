//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 10 04 2020

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

#define    ll   long long

int a, b, c;

void sortt()
{
    int x, y;

    if(a<=b&&a<=c){
        x = min(b, c);
        y = max(b, c);
        b = x;
        c = y;
    }
    else if(b<=a&&b<=c){
        x = max(a, c);
        y = min(a, c);
        a = b;
        b = y;
        c = x;
    }
    else if(c<=a&&c<=b){
        x = max(a, b);
        y = min(a, b);
        a = c;
        b = y;
        c = x;
    }
}

void task()
{
    int n, i=1, j=0, k=0, mid, ans = 0;

    cin >> n >> a >> b >> c;

    sortt();

    //cout << a << ' ' << b << ' ' << c << endl;

    if(n%a==0){
        cout << n/a << endl;
        return;
    }

    i=0; j=0;
    bool flag = 0;
    int count=0;
    while(1){
        if(j>4000) break;
        while(1){
            if(i>4000){
                i=0;
                break;
            }
            //if(i==1) cout << "hi" << endl;
            mid = n-(i*a+j*b);
            if(mid==0) ans = max(ans, (i+j));
            else if(mid>0 && mid%c==0){
                mid = mid/c;

                if(n==(i*a+j*b+mid*c))ans = max(ans, (i+j+mid));
            }

            i++;
        }


        j++;
    }

    cout << ans << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

