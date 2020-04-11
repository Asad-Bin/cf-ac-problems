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

vector<bool> mark(10000002);
vector<ll> prime;

void sieve()
{
    ll i, j, root, n=10000002;
    root=sqrt(n+1)+2;

    //vector<bool> mark(n+10);

    mark[1]=1;

    for(i=4; i<=n; i+=2) mark[i]=1;

    prime.push_back(2);
    for(i=3; i<=n; i+=2){
        if(!mark[i]){
            prime.push_back(i);
            if(i<=root){
                for(j=i*i; j<=n; j+=i*2){
                    mark[j]=1;
                }
            }
        }
    }
}

void task()
{
    ll t, x;
    double mid;
    sieve();
    //cout << "hi" << endl;

    cin >> t;

    for(ll K=0; K<t; K++){
        cin >> x;
        mid = sqrt(x);

        if(x==3 || x==2 || x==1) {
            cout << "NO" << endl;
            continue;
        }


        if(ceil(mid)-floor(mid)<0.00001){
            int p = floor(mid);

            if(mark[p]==0){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
        else cout << "NO" << endl;
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
