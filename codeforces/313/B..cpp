//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 17 04 2020

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;

typedef long long ll;
const int MX=1e5;
const int MN=-1e5;

#define    pi    acos(-1.0)
//#define

void task()
{
    string str;
    int n, l, r;

    cin >> str >> n;

    int len = str.length();
    vector<int> ara(len+1);

    if(str[0]==str[1]){
        ara[0] = 0;
        ara[1] = 1;
    }
    else{
        ara[0] = 0;
        ara[1] = 0;
    }

    for(int K=1; K<len; K++){
        if(K==len-1){
            ara[K+1] = ara[K];
            //cout << ara[K] << "\n";
            break;
        }
        if(str[K]==str[K+1]){
            ara[K+1] = ara[K] + 1;
            //ara[K+1] = ara[K];
        }
        else{
            ara[K+1] = ara[K];
        }
    }
    //ara[len] = ara[len-1];

    while(n--){
        cin >> l >> r;

        cout << ara[r-1]-ara[l-1] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}

