//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 10 04 2020

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
    ll n, i=0;
    cin >> n;

    vector<string> name(n);
    vector<long int> ara(n);
    bool flag = 0;


    while(n--){
        cin >> name[i];

        for(ll K=i-1; K>=0; K--){
            if(name[i]==name[K]){
                flag = 1;
                ara[i] = ara[K]+1;
                break;
            }
        }
        if(flag==1) cout << name[i] << ara[i] << endl;
        else cout << "OK" << endl;
        flag = 0;
        i++;
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

