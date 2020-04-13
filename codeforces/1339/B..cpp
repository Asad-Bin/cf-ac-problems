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
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> ara(n);
        vector<int> ans;

        for(int K=0; K<n; K++) cin >> ara[K];

        sort(ara.begin(), ara.end());


        for(int K=0; 2*K<n; K++){
            ans.push_back(ara[K]);
            ans.push_back(ara[n-1-K]);
        }
        if(n%2==1) ans.push_back(ara[(n-1)/2]);

        for(int K=n-1; K>=0; K--){
            cout << ans[K] << ' ';
        }
        cout << endl;

        //cout << "hi" << endl;
    }
}

int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
