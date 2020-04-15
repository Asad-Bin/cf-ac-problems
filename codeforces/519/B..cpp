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
    ll n, ans;

    cin >> n;

    vector<long int> fird(n);
    vector<long int> second(n-1);

    for(long int K=0; K<n; K++) cin >> fird[K];

    sort(fird.begin(), fird.end());

    for(long int K=0; K<n-1; K++) cin >> second[K];

    sort(second.begin(), second.end());

    for(long int K=0; K<n; K++){
        if(K==n-1){
            ans = fird[K];
            break;
        }
        if(fird[K]!=second[K]){
            ans = fird[K];
            break;
        }
    }

    cout << ans << "\n";

    for(long int K=0; K<n-2; K++) cin >> fird[K];

    sort(fird.begin(), fird.begin()+n-2);

    for(long int K=0; K<n-1; K++){
        if(K==n-2){
            ans = second[K];
            break;
        }
        if(fird[K]!=second[K]){
            ans = second[K];
            break;
        }
    }

    cout << ans << "\n";
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

