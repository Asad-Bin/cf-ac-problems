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

ll n;


vector<bool> sieve()
{
    ll i, j, root=sqrt(n+1)+2;

    vector<bool> mark(n+10);

    mark[1]=1;

    for(i=4; i<=n; i+=2) mark[i]=1;

    for(i=3; i<=n; i+=2){
        if(!mark[i]){
            if(i<=root){
                for(j=i*i; j<=n; j+=i*2){
                    mark[j]=1;
                }
            }
        }
    }

    return mark;
}

void task()
{
    ll mid;
    cin >> n;
    vector<bool> mark;

    mark = sieve();

    for(ll K=4; K<n; K+=2){
        mid = n - K;
        if(mark[mid]==1){
            cout << K << ' ' << mid << endl;
            return;
        }
    }
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
