//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 08 04 2020

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
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;

        for(int K=1; K<=n; K++){
            for(int L=1; L<=m; L++){
                if(K==1 && L==1) cout << 'W';
                else cout << 'B';
            }
            cout << endl;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    return 0;
}

