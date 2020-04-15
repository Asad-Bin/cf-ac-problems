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
    ll len, ans;
    bool flag=0;
    string str;

    cin >> len >> str;
    ans = len;

    vector<char> finale(len);

    for(ll K=0; K<len; K++) finale[K] = str[K];

    //while(1){
        //flag = 0;

        for(ll K=0; K<ans-1; K++){
            if(finale[K]=='1' && finale[K+1]=='0'){
                finale.erase(finale.begin()+K);
                finale.erase(finale.begin()+K);
                ans-=2;
                flag = 1;
                K-=2;
                //cout << "hi";
            }
            else if(finale[K]=='0' && finale[K+1]=='1'){
                finale.erase(finale.begin()+K);
                finale.erase(finale.begin()+K);
                ans-=2;
                flag = 1;
                K-=2;
            }
        }
        //if(ans==0) break;

        //if(flag==0) break;
    //}

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

