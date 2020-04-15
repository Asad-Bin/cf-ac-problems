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
    ll n, m, x, q, hi, lo, mid;
    bool flag=0;

    cin >> n >> x;

    vector<ll> ara(n);

    ara[0] = x;
    for(ll K=1; K<n; K++){
        cin >> x;
        ara[K] = x + ara[K-1];
    }

    cin >> m;
    ll one = (int)(n-1)/4, two = (int)(n-1)/2, three = (int)(n-1)*3/4, L;
    for(ll K=0; K<m; K++){
        cin >> q;

        hi = n-1;
        lo = 0;
        while(1){
            flag=0;
            if(hi-lo<=10){
                for(int K=lo; K<=hi; K++){
                    if(ara[K]>=q){
                        cout << K+1 << endl;
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1) break;
            mid = (hi+lo)/2;
            if(q==ara[mid]){
                cout << mid+1 << endl;
                break;
            }
            else if(q>ara[mid]) lo = mid;
            else hi = mid;
        }
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

