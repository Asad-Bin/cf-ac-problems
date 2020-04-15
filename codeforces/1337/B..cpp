//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 15 04 2020

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
     ll t, h, n, m, ans;

     cin >> t;
     while(t--){
        cin >> h >> n >> m;
        ans = h;

        ans -= m*10;
        if(ans<=0){
            cout << "yes" << endl;
            continue;
        }

        for(ll K=1; K<=n; K++){
            h = h/2+10;
        }
        h -= m*10;

         if(h<=0) cout << "yes" << endl;
         else cout << "no" << endl;
     }
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

