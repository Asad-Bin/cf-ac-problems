//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 16 04 2020

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;

#define    ll   long long
#define    pi   acos(-1.0)

void task()
{
    int n, m, save, p;

    cin >> n >> m;

    save = 10001;
    if(n%m==0) save = n;
    if(n<m) save = -1;
    p = n;

    for(int K=1; K<=p; K+=2){
        n--;
        if(2*n<p) break;
        //if(n==5000) cout << "yes" << endl;

        if(n!=0 && n%m==0){
            if(save>n) save = n;
        }
    }

    if(save==10001) cout << "-1" << "\n";
    else cout << save << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}

