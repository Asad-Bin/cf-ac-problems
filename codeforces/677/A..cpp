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
    int n, h, x, count=0;

    cin >> n >> h;

    //vector<int> ara(n);

    for(int K=0; K<n; K++){
        cin >> x;

        if(x>h){
            count+=2;
        }
        else count++;
    }

    cout << count << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
