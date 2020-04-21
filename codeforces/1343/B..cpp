//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 21 04 2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define    pi    acos(-1.0)

void task()
{
    ll t, n, mid;

    cin >> t;
    while(t--){
        cin >> n;

        if(n%4!=0){
            cout << "NO\n";
        }
        else{
            mid = n/4;

            cout << "YES\n";

            for(ll K=2; K<=n; K+=2){
                cout << K << ' ';
            }
            for(ll K = 1; 2*K<n; K+=2){
                cout << K << ' ';
            }
            for(ll K = n/2 + 3; K<=n+1; K+=2){
                cout << K << ' ';
            }
            cout << "\n";
        }
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

