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
    ll n, x;
    vector<ll> v;

    cin >> n >> x;

    for(ll K=1; K*K<=x && K<=n; K++){
        if(x%K==0){
            if(K<=n && x<=n*K){
                if(K*K==x){
                    v.push_back(K);
                    continue;
                }
                v.push_back(K);
                v.push_back(x/K);
            }
        }
    }

    cout << v.size() << endl;
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

