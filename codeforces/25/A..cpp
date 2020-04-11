//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 11 04 2020

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
    int n, even=0, odd=0, ind_ev, ind_od, x;

    cin >> n;
    for(int K=1; K<=n; K++){
        cin >> x;
        if(x%2==0){
            even++;
            ind_ev=K;
        }
        else{
            odd++;
            ind_od=K;
        }
    }

    if(even==1) cout << ind_ev << endl;
    else cout << ind_od  << endl;
}

int main()
{
    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
