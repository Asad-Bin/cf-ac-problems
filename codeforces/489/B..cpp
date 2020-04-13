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
    int n, m, count=0;

    cin >> n;
    vector<int> boy(n);
    vector<int> live(n);
    for(int K=0; K<n; K++) cin >> boy[K];

    cin >> m;
    vector<int> girl(m);
    vector<bool> die(m);
    for(int K=0; K<m; K++) cin >> girl[K];

    sort(boy.begin(), boy.end());
    sort(girl.begin(), girl.end());

    for(int K=0; K<n; K++){
        for(int L=0; L<m; L++){
            if(!die[L] && !live[K] && abs(boy[K]-girl[L])<=1){
                count++;
                die[L] = 1;
                live[K] = 1;
            }
        }
    }

    cout << count << endl;
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

