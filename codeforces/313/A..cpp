//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 13 04 2020

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;

#define    ll   long long

void task()
{
    ll n;

    cin >> n;

    if(n>=0){
        cout << n << endl;
    }
    else {
        int op_one = n/10;
        int op_two = abs(n) % 10;
        //cout << op_two;
        n /= 100;
        n *= 10;
        op_two = n - op_two;

        cout << max(op_one, op_two) << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
