//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 10 04 2020

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

#define    ll   long long

void task()
{
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        bool flag = 0;
        vector<int> p(n);
        vector<int> c(n);

        for(int K=0; K<n; K++){
            cin >> p[K] >> c[K];
        }

        if(n==1){
            if(c[0]>p[0]) flag=1;

            if(flag==1) cout << "NO" << endl;
            else cout << "YES" << endl;
            continue;
        }


        for(int K=0; K<n-1; K++){
            if(p[K]>p[K+1]) flag = 1;
            if(c[K]>c[K+1]) flag = 1;
            if(c[K]>p[K]) flag = 1;
            if((c[K+1]-c[K])>(p[K+1]-p[K])) flag=1;
        }
        //if(c[n-1]>c[n-2] && p[n-1]==p[n-2]) flag =1;
        if(c[n-1]>p[n-1]) flag=1;

        if(flag==1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
