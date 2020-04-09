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
    int n, x;

    cin >> n;
    //vector<int> ara(n+1);
    vector<int> res(n+1);

    for(int K=1; K<=n; K++){
        cin >> x;
        res[x] = K;
    }

    for(int K=1; K<=n; K++) cout << res[K] << ' ';
    cout << "\n";
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
