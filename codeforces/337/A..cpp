//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 09 04 2020

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
    int n, m, min_=1000, dif;
    cin >> n >> m;
    vector<int> ara(m);

    for(int K=0; K<m; K++){
        cin >> ara[K];
    }

    sort(ara.begin(), ara.end());

    for(int K=0; K<m-1; K++){
        for(int L=K+1; L<m; L++){
            if(n==L-K+1){
                dif = ara[L]-ara[K];
                if(dif<min_) min_ = dif;
            }
        }
    }

    cout << min_ << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}
