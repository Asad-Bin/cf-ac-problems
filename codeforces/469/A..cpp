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

void task()
{
    int n, x, p;

    cin >> n;
    vector<bool> ara(n);

    cin >> x;
    while(x--){
        cin >> p;

        ara[p] = 1;
    }

    cin >> x;
    while(x--){
        cin >> p;

        ara[p] = 1;
    }

    for(int K=1; K<=n; K++){
        if(ara[K]==0){
            cout << "Oh, my keyboard!" << endl;
            return;
        }
    }

    cout << "I become the guy." << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

