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
    ll n, t;

    cin >> t;
    while(t--){
        cin >> n;

        ll distinct=0, repeat=0, ans, x;
        vector<ll> ara(n+1);
        vector<bool> mark(n+1);

        for(int K=0; K<n; K++){
            cin >> x;
            ara[x]++;
            repeat = max(repeat, ara[x]);
            if(mark[x]==0) distinct++;
            mark[x] = 1;
        }
        //cout << distinct << ' ' << repeat << endl;

        if(distinct==repeat){
            ans = distinct-1;
        }
        else if(repeat>distinct){
            ans = min(distinct, repeat);
        }
        else{
            ans = min(distinct, repeat);
        }

        cout << ans << endl;
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

